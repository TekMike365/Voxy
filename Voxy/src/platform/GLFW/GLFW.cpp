#include "GLFW.hpp"

#include "Log.hpp"
#include <GLFW/glfw3.h>
#include <imgui.h>

namespace Voxy {

void ErrorCallback(int error, const char *description) {
    VoxyCoreError("GLFW ({}): {}", error, description);
}

void Platform::GLFW_Init() {
    glfwSetErrorCallback(ErrorCallback);
    VoxyAssert(glfwInit(), "GLFW: failed to initialize.");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    IMGUI_CHECKVERSION();
}

void Platform::GLFW_Terminate() { glfwTerminate(); }

} // namespace Voxy