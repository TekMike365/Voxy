#include "Voxy/IWindow.h"
#include "GLFW/GLFWWindow.h"

#include "Log.h"

namespace Voxy
{
    Ref<IWindow> IWindow::CreateWindow(const WindowParams &params)
    {
        VOXY_CORE_TRACE("Creating window");
        return Ref<IWindow>(new GLFW::Window(params));
    }
}

