#include "GLFW.hpp"

#include "Log.hpp"
#include <GLFW/glfw3.h>

namespace Voxy {

void Platform::GLFW_Init() {
    VoxyAssert(glfwInit(), "GLFW: failed to initialize.")
}

void Platform::GLFW_Terminate() { glfwTerminate(); }

} // namespace Voxy