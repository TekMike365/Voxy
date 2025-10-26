#include "Application.hpp"

#include "Log.hpp"
#include "Platform/Platform.hpp"
#include <GLFW/glfw3.h>

namespace Voxy {

Application::Application() {
    _window = Platform::CreateWindow();
    _window->MakeContextCurrent();
}

Application::~Application() {}

void Application::Run() {
    Log::Info("Application started.");

    _running = true;
    while (_running) {
        // Render
        glClearColor(RGBto3f(0xf4a261), 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

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
