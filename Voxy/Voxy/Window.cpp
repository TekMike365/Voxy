#include "Window.h"

#include "Platform/GLFW/Window.h"

namespace Voxy
{
    Ref<Window> Window::CreateWindow(const WindowParams &params)
    {
        VOXY_CORE_TRACE("Creating window");
        return Ref<Window>(new GLFW::Window(params));
    }
}
