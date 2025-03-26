#include "Setup.h"

#include <GLFW/glfw3.h>

#include "Log.h"

void Voxy::Init()
{
    Log::Init();

    VOXY_CORE_INFO("Initializing");

    // Initialize GLFW
    if (!glfwInit())
    {
        VOXY_CORE_ERROR("Failed to initialize GLFW!");
        return;
    }
}

void Voxy::Shutdown()
{
    VOXY_CORE_INFO("Shutting down");
    glfwTerminate();
}
