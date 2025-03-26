#include "Voxy.h"

#include <GLFW/glfw3.h>

#include "Log.h"

void Voxy::Init()
{
    Log::Init();

    // Initialize GLFW
    if (!glfwInit())
    {
        VOXY_CORE_ERROR("Failed to initialize GLFW!");
        return;
    }
}

void Voxy::Shutdown()
{
    glfwTerminate();
}
