#include <GLFW/glfw3.h>

#include "Events/WindowEvents.hpp"
#include "Log.hpp"
#include "Window.hpp"
#include "platform/GLFW/GLFW.hpp"
#include "platform/GLFW/GLFW_Window.hpp"

bool g_Running = true;

bool OnWindowClose(Voxy::WindowCloseEvent &e) {
    VoxyCoreWarn("Shutting down");
    g_Running = false;
    return true;
}

void WndEventCallback(Voxy::Event &e) {
    using namespace Voxy;

    EventDispatcher dispatcher(e);
    dispatcher.Dispatch<Voxy::WindowCloseEvent>(OnWindowClose);
}

int main(void) {
    Voxy::Log::Init();
    VoxyCoreInfo("Initialized logger.");
    Voxy::Platform::GLFW_Init();

    auto wnd = Voxy::Window::Create({.Callback = WndEventCallback});

    /* Make the window's context current */
    glfwMakeContextCurrent((GLFWwindow *)wnd->GetHandle());

    /* Loop until the user closes the window */
    while (g_Running) {
        wnd->Update();
    }

    Voxy::Platform::GLFW_Terminate();
}
