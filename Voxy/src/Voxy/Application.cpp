#include "Application.hpp"

#include "Platform/Platform.hpp"
#include <GLFW/glfw3.h>

namespace Voxy {

Application::Application() {}

Application::~Application() {}

void Application::Run() {
    /* Initialize the library */
    if (!glfwInit())
        return;

    Ref<IWindow> wnd1 = Platform::CreateWindow();
    Ref<IWindow> wnd2 = Platform::CreateWindow();

    bool running = true;
    /* Loop until the user closes the window */
    while (running) {
        if (wnd1)
            wnd1->Update();
        if (wnd2)
            wnd2->Update();

        if (wnd1 && wnd1->ShouldClose())
            wnd1.reset();
        if (wnd2 && wnd2->ShouldClose())
            wnd2.reset();

        if (!wnd1 && !wnd2)
            running = false;
    }

    glfwTerminate();
}

} // namespace Voxy
