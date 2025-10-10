#include "OpenGL.hpp"
#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include "Log.hpp"

bool g_IsInitialized = false;

namespace Voxy::Platform {

void OpenGL::Init() {
    if (g_IsInitialized)
        return;

    VoxyAssert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress),
               "GLAD: Failed to load OpenGL");
    g_IsInitialized = true;
}

} // namespace Voxy::Platform
