#include "OpenGL.hpp"
#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include "Log.hpp"

namespace Voxy {

bool g_IsInitialized = false;

void OpenGL_Init() {
    if (g_IsInitialized)
        return;

    VoxyAssert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress),
               "GLAD: Failed to load OpenGL");
    g_IsInitialized = true;
}

void OpenGL_Terminate() {
    if (!g_IsInitialized)
        return;

    g_IsInitialized = false;
}

} // namespace Voxy
