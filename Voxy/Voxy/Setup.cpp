#include "Setup.h"

#include <GLFW/glfw3.h>

#include "Log.h"

void Voxy::Init()
{
    Log::Init();

    VOXY_CORE_INFO("Initializing");

    // Initialize GLFW
    VOXY_ASSERT(glfwInit(), "Failed to initialize GLFW!");
}

void Voxy::Shutdown()
{
    VOXY_CORE_INFO("Shutting down");
    glfwTerminate();
}
