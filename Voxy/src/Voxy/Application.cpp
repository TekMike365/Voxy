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

    auto *context = _window->GetContext();
    context->MakeCurrent();

    _running = true;
    while (_running) {
        context->BeginFrame();

        ImGui::ShowDemoWindow();

        _window->Update();

        if (wnd2) {
            wnd2->Update();
            if (wnd2->ShouldClose())
                wnd2.reset();
        }

        context->Render();

        if (_window->ShouldClose())
            Quit();
    }
}

void Application::Quit() {
    Log::Info("Exitting application.");
    _running = false;
}

} // namespace Voxy
