#include "GLFW.hpp"

#include <GLFW/glfw3.h>
#include <imgui.h>

#include "Log.hpp"

void ErrorCallback(int error, const char *description) {
    VoxyCoreError("GLFW ({}): {}", error, description);
}

namespace Voxy::Platform {

void GLFW::Init() {
    glfwSetErrorCallback(ErrorCallback);
    VoxyAssert(glfwInit(), "GLFW: failed to initialize.");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    IMGUI_CHECKVERSION();
}

void GLFW::Terminate() { glfwTerminate(); }

} // namespace Voxy