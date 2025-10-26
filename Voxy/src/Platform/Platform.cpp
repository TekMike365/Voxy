#include "Platform.hpp"

#include <glad/glad.h>

#include "GLFW/GLFW.hpp"
#include "GLFW/GLFWWindow.hpp"
#include <cassert>

namespace Voxy::Platform {

void Init() {
    GLFWInit();
    assert(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress));
}

void Terminate() { GLFWTerminate(); }

Ref<IWindow> CreateWindow(const WindowParams &params) {
    return std::make_shared<GLFWWindow>(params);
}

} // namespace Voxy::Platform
