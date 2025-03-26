#include "Voxy/Window.h"
#include "GLFW/GLFWWindow.h"

#include "Log.h"

namespace Voxy
{
    Ref<Window> Window::CreateWindow(const WindowParams &params)
    {
        VOXY_CORE_TRACE("Creating window");
        return Ref<Window>(new GLFW::Window(params));
    }
}

