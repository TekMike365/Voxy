#include "Window.h"
#include "GLFW/GLFWWindow.h"

namespace Voxy
{
    Ref<Window> Window::CreateWindow(const WindowParams &params)
    {
        return Ref<Window>(new GLFW::Window(params));
    }
}

