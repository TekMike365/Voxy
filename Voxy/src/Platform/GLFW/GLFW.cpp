#include "GLFW.hpp"

#include "Log.hpp"
#include <GLFW/glfw3.h>

namespace Voxy::Platform {

void GLFWInit() {
    glfwSetErrorCallback([](int error, const char *description) {
        Log::Error("GLFW error ({}): {}", error, description);
    });

    if (!glfwInit())
        return;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
}

void GLFWTerminate() { glfwTerminate(); }

} // namespace Voxy::Platform
