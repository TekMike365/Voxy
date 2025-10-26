#include "Platform.hpp"

#include "GLFW/GLFWWindow.hpp"

namespace Voxy::Platform {

void Init() {
    if (!glfwInit())
        return;
}

void Terminate() { glfwTerminate(); }

Ref<IWindow> CreateWindow(const WindowParams &params) {
    return std::make_shared<GLFWWindow>(params);
}

} // namespace Voxy::Platform
