#include "Application.hpp"

#include "ImGuiManager.hpp"
#include "Log.hpp"
#include "Platform/Platform.hpp"
#include <GLFW/glfw3.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace Voxy {

Application *Application::s_Instance = nullptr;

Application::Application() {
    if (s_Instance)
        assert(0);
    s_Instance = this;

    m_Rindow = Platform::CreateWindow();
}

Application::~Application() { s_Instance = nullptr; }

void Application::Run() {
    Log::Info("Application started.");

    auto &context = m_Rindow->GetContext();

    m_Running = true;
    while (m_Running) {
        ImGuiManager::BeginFrame();

        ImGui::ShowDemoWindow();

        ImGuiManager::EndFrame();

        context.MakeCurrent();

        // Render
        auto &wndParams = m_Rindow->GetParams();
        glViewport(0, 0, wndParams.width, wndParams.height);
        glClearColor(RGBto3f(0xf4a261), 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(ImGuiManager::GetDrawData());

        context.SwapBuffers();

        m_Rindow->Update();

        if (m_Rindow->ShouldClose())
            Quit();
    }
}

void Application::Quit() {
    Log::Info("Exitting application.");
    m_Running = false;
}

} // namespace Voxy
