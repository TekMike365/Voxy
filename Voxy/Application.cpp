#include "Application.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>

#include "Log.h"

#define BIND_APP_EVENT(fn) std::bind(&Application::fn, this, std::placeholders::_1)

namespace Voxy
{
    Application::Application()
    {
        m_Window = Window::CreateWindow();
        m_Window->SetEventCallback(BIND_APP_EVENT(OnEvent));
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {

        ImGuiIO &io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls

        bool show_demo_window = true;
        ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

        while (m_IsRunning)
        {
            m_Window->OnUpdate();

            // Start the Dear ImGui frame
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            // 1. Show demo window
            if (show_demo_window)
                ImGui::ShowDemoWindow();

            // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
            {
                static float f = 0.0f;
                static int counter = 0;

                ImGui::Begin("Hello, world!"); // Create a window called "Hello, world!" and append into it.

                ImGui::Text("This is some useful text.");          // Display some text (you can use a format strings too)
                ImGui::Checkbox("Demo Window", &show_demo_window); // Edit bools storing our window open/close state

                ImGui::SliderFloat("float", &f, 0.0f, 1.0f);             // Edit 1 float using a slider from 0.0f to 1.0f
                ImGui::ColorEdit3("clear color", (float *)&clear_color); // Edit 3 floats representing a color

                if (ImGui::Button("Button")) // Buttons return true when clicked (most widgets return true when edited/activated)
                    counter++;
                ImGui::SameLine();
                ImGui::Text("counter = %d", counter);

                ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
                ImGui::End();
            }

            // Rendering
            ImGui::Render();

            int display_w, display_h;
            glfwGetFramebufferSize((GLFWwindow *)m_Window->GetWindowHandle(), &display_w, &display_h);
            glViewport(0, 0, display_w, display_h);
            glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
            glClear(GL_COLOR_BUFFER_BIT);

            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        }
    }

    void Application::OnEvent(Event &e)
    {
        EventDispatcher d(e);
        d.Dispatch<WindowCloseEvent>(BIND_APP_EVENT(OnWindowClose));
    }

    bool Application::OnWindowClose(WindowCloseEvent &e)
    {
        VOXY_WARN("Closing window!");
        m_IsRunning = false;
        return true;
    }
}