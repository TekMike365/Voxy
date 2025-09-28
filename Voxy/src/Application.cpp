#include "Application.hpp"

#include "Layers/GUILayer.hpp"
#include "Log.hpp"
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#define BIND_APP_EVENT(fn)                                                     \
    std::bind(&Application::fn, this, std::placeholders::_1)

namespace Voxy {

Application *Application::s_Instance = nullptr;

Application::Application() {
    VoxyAssert(!s_Instance, "There can oly be one instance of Application");
    s_Instance = this;

    m_Window = Voxy::Window::Create({.Callback = BIND_APP_EVENT(OnEvent)});

    m_LayerStack.PushLayer(new GUILayer);
}

Application::~Application() {}

void Application::Run() {
    // IO stuff
    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |=
        ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    io.ConfigFlags |=
        ImGuiConfigFlags_NavEnableGamepad; // Enable Gamepad Controls

    // Our state
    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    VoxyCoreInfo("Main loop started");
    while (m_IsRunning) {
        for (Layer *layer : m_LayerStack)
            layer->OnUpdate();

        // 1. Show the big demo window (Most of the sample code is in
        // ImGui::ShowDemoWindow()! You can browse its code to learn more about
        // Dear ImGui!).
        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        // 2. Show a simple window that we create ourselves. We use a Begin/End
        // pair to create a named window.
        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!"); // Create a window called "Hello,
                                           // world!" and append into it.

            ImGui::Text(
                "This is some useful text."); // Display some text (you can
                                              // use a format strings too)
            ImGui::Checkbox("Demo Window",
                            &show_demo_window); // Edit bools storing our window
                                                // open/close state
            ImGui::Checkbox("Another Window", &show_another_window);

            ImGui::SliderFloat(
                "float", &f, 0.0f,
                1.0f); // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3(
                "clear color",
                (float *)&clear_color); // Edit 3 floats representing a color

            if (ImGui::Button(
                    "Button")) // Buttons return true when clicked (most widgets
                               // return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
                        1000.0f / io.Framerate, io.Framerate);
            ImGui::End();
        }

        // 3. Show another simple window.
        if (show_another_window) {
            ImGui::Begin(
                "Another Window",
                &show_another_window); // Pass a pointer to our bool variable
                                       // (the window will have a closing button
                                       // that will clear the bool when clicked)
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
                show_another_window = false;
            ImGui::End();
        }

        m_Window->Update();
    }
}

void Application::OnEvent(Event &e) {
    EventDispatcher d(e);

    bool handled =
        d.Dispatch<Voxy::WindowCloseEvent>(BIND_APP_EVENT(OnWindowClose));

    if (handled)
        return;

    for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); it++)
        if ((*it)->OnEvent(e))
            break;
}

bool Application::OnWindowClose(WindowCloseEvent &e) {
    VoxyCoreWarn("Shutting down");
    m_IsRunning = false;
    return true;
}

} // namespace Voxy
