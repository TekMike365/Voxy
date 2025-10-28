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

    _window = Platform::CreateWindow();
}

Application::~Application() { s_Instance = nullptr; }

void Application::Run() {
    Log::Info("Application started.");

    auto &context = _window->GetContext();

    _running = true;
    while (_running) {
        ImGuiManager::BeginFrame();

        ImGui::ShowDemoWindow();

        ImGuiManager::EndFrame();

        context.MakeCurrent();

        // Render
        auto &wndParams = _window->GetParams();
        glViewport(0, 0, wndParams.width, wndParams.height);
        glClearColor(RGBto3f(0xf4a261), 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(ImGuiManager::GetDrawData());

        context.SwapBuffers();

        _window->Update();

        if (_window->ShouldClose())
            Quit();
    }
}

void Application::Quit() {
    Log::Info("Exitting application.");
    _running = false;
}

} // namespace Voxy
