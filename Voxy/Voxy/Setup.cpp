#include "Setup.h"

#include <GLFW/glfw3.h>

#include "Log.h"

void Voxy::Init()
{
    Log::Init();

    VOXY_CORE_INFO("Initializing");

    // Initialize GLFW
    VOXY_ASSERT(glfwInit(), "Failed to initialize GLFW!")
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Voxy::Shutdown()
{
    VOXY_CORE_INFO("Shutting down");
    glfwTerminate();
}
