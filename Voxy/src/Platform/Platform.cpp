#include "Platform.hpp"

#include "GLFW/GLFW.hpp"
#include "GLFW/GLFWWindow.hpp"

namespace Voxy::Platform {

void Init() { GLFWInit(); }

void Terminate() { GLFWTerminate(); }

Ref<IWindow> CreateWindow(const WindowParams &params) {
    return std::make_shared<GLFWWindow>(params);
}

} // namespace Voxy::Platform
