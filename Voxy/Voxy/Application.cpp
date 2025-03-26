#include "Application.h"

#include <chrono>
#include <imgui.h>

#include "Log.h"
#include "Helpers.h"
#include "Layers/ImGuiLayer.h"
#include "Layers/RenderingLayer.h"

#define BIND_APP_EVENT(fn) std::bind(&Application::fn, this, std::placeholders::_1)

namespace Voxy
{
    Application::Application()
    {
        m_Window = Window::CreateWindow();
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