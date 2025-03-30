#include "Application.h"

#include <chrono>
#include <imgui.h>

#include "Log.h"
#include "Helpers.h"
#include "Layers/ImGuiLayer.h"
#include "Layers/RenderingLayer.h"

#include "Renderer/VertexArray.h"
#include "Renderer/Shader.h"
#include "Renderer/Renderer.h"

#define BIND_APP_EVENT(fn) std::bind(&Application::fn, this, std::placeholders::_1)

namespace Voxy
{
    Application *Application::s_Instance = nullptr;

    Application::Application()
    {
        VOXY_ASSERT(!s_Instance, "Application already exists")
        s_Instance = this;

        m_Window = Window::Create();
        m_Window->SetEventCallback(BIND_APP_EVENT(OnEvent));

        m_LayerStack.PushOverlay(std::make_shared<RenderingLayer>());
        m_LayerStack.PushOverlay(std::make_shared<ImGuiLayer>());
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        auto last = std::chrono::high_resolution_clock::now();
        TimeStep dt;

        const float vertices[] = {
             0.0f,  0.5f, -1.0f, 1.0f, 0.0f, 0.0f,
            -0.5f, -0.5f, -1.0f, 0.0f, 1.0f, 0.0f,
             0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,

             0.5f, -0.5f, -1.0f, 0.0f, 1.0f, 1.0f,
             0.0f,  0.5f, -1.0f, 1.0f, 0.0f, 1.0f,
             1.0f,  0.5f, -1.0f, 1.0f, 1.0f, 0.0f,
        };

        const float offsets[] = {
            -0.5f, 0.0f, 0.0f,
             0.5f, 0.0f, 0.0f,
        };

        const uint32_t indices[] = {
            0, 1, 2,
            3, 4, 5
        };

        const char* vertexSource = R"(
            #version 430 core

            layout (location = 0) in vec3 aPos;
            layout (location = 1) in vec3 aColor;
            layout (location = 2) in vec3 aOffset;

            uniform mat4 uProjection;

            out vec3 vColor;

            void main()
            {
                vColor = aColor;
                gl_Position = uProjection * vec4(aPos + aOffset, 1.0);
            }
        )";

        const char* fragmentSource = R"(
            #version 430 core

            in vec3 vColor;
            out vec4 fColor;

            void main()
            {
                fColor = vec4(vColor, 1.0);
            }
        )";

        using namespace Renderer;

        Ref<Buffer> vertexBuffer = Buffer::Create(BufferType::Vertex, sizeof(vertices), vertices);
        Ref<Buffer> indexBuffer = Buffer::Create(BufferType::Index, sizeof(indices), indices);

        Ref<Buffer> offsetsBuffer = Buffer::Create(BufferType::Vertex, sizeof(offsets), offsets);

        Ref<VertexArray> vertexArray = VertexArray::Create(indexBuffer);
        vertexArray->AddObject(0, 3, "triangle");
        vertexArray->AddObject(3, 3, "inversedTriangle");
        vertexArray->AddAttribute(VertexAttribute(0, STfloat3, 0, 24, vertexBuffer));
        vertexArray->AddAttribute(VertexAttribute(1, STfloat3, 12, 24, vertexBuffer));
        vertexArray->AddAttribute(VertexAttribute(2, STfloat3, 0, 12, offsetsBuffer, 1));

        Ref<Shader> shader = Shader::Create(vertexSource, fragmentSource);
        
        Ref<Camera> camera = std::make_shared<Camera>(120.0f, m_Window->GetAspect());

        VOXY_CORE_INFO("Main loop started");

        while (m_IsRunning)
        {
            m_Window->OnUpdate();

            {
                // TODO: Cleanup
                // Debug Screen
                ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav;
                const float PAD = 10.0f;
                const ImGuiViewport *viewport = ImGui::GetMainViewport();
                ImVec2 work_pos = viewport->WorkPos; // Use work area to avoid menu-bar/task-bar, if any!
                ImVec2 work_size = viewport->WorkSize;
                ImVec2 window_pos, window_pos_pivot;
                window_pos.x = work_pos.x + work_size.x - PAD;
                window_pos.y = work_pos.y + PAD;
                window_pos_pivot.x = 1.0f;
                window_pos_pivot.y = 0.0f;
                ImGui::SetNextWindowPos(window_pos, ImGuiCond_Always, window_pos_pivot);
                window_flags |= ImGuiWindowFlags_NoMove;
                ImGui::SetNextWindowBgAlpha(0.35f); // Transparent background
                if (ImGui::Begin("Example: Simple overlay", NULL, window_flags))
                {
                    ImGui::Text("%.3f ms (%.1f FPS)", dt.GetMiliseconds(), 1.0f / dt.GetSeconds());
                }
                ImGui::End();
            }

            for (auto layer : m_LayerStack)
                layer->OnUpdate(dt);

            Renderer::Begin(camera);
            Renderer::Submit(vertexArray, shader, "triangle", 2);
            Renderer::Submit(vertexArray, shader, "inversedTriangle");
            Renderer::End();

            auto now = std::chrono::high_resolution_clock::now();
            dt = std::chrono::duration<float>(now - last).count();
            last = now;
        }
    }

    void Application::OnEvent(Event &e)
    {
        EventDispatcher d(e);
        d.Dispatch<WindowCloseEvent>(BIND_APP_EVENT(OnWindowClose));

        for (auto layer = m_LayerStack.rbegin(); layer != m_LayerStack.rend(); layer++)
            if (layer->get()->OnEvent(e))
                break;
    }

    bool Application::OnWindowClose(WindowCloseEvent &e)
    {
        VOXY_CORE_WARN("Closing window!");
        m_IsRunning = false;
        return true;
    }
}