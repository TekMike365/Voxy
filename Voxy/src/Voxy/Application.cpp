#include "Application.hpp"

#include "Log.hpp"
#include "Platform/Platform.hpp"
#include <GLFW/glfw3.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace Voxy {

Application::Application() { _window = Platform::CreateWindow(); }

Application::~Application() {}

void Application::Run() {
    Log::Info("Application started.");

    auto wnd2 = Platform::CreateWindow({640, 480, "wnd2"});

    auto &context = _window->GetContext();
    context.MakeCurrent();

    _running = true;
    while (_running) {
        BeginFrame();

        ImGui::ShowDemoWindow();

        // Render
        ImGui::Render();
        auto &wndParams = _window->GetParams();
        glViewport(0, 0, wndParams.width, wndParams.height);
        glClearColor(RGBto3f(0xf4a261), 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        context.SwapBuffers();

        _window->Update();

        if (wnd2) {
            wnd2->Update();
            if (wnd2->ShouldClose())
                wnd2.reset();
        }

        EndFrame();

        if (_window->ShouldClose())
            Quit();
    }
}

void Application::Quit() {
    Log::Info("Exitting application.");
    _running = false;
}

void Application::BeginFrame() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void Application::EndFrame() {}

} // namespace Voxy
