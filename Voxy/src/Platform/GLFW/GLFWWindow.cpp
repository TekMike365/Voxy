#include "GLFWWindow.hpp"

#include "Helpers.hpp"
#include "Log.hpp"
#include <cassert>

namespace Voxy::Platform {

GLFWWindow::GLFWWindow(const WindowParams &params)
    : _params(params), _shouldClose(false) {
    _hwnd = glfwCreateWindow(_params.width, _params.height,
                             _params.title.c_str(), NULL, NULL);
    _context = std::make_unique<GLFWGraphicsContext>(_hwnd);

    Log::Trace("GLFW window created: {} (0x{:x})", _params.title,
               (size_t)_hwnd);
}

GLFWWindow::~GLFWWindow() {
    _context.reset(); // destroy context
    glfwDestroyWindow(_hwnd);

    Log::Trace("GLFW window terminated: {} (0x{:x})", _params.title,
               (size_t)_hwnd);
}

void GLFWWindow::Update() {
    _shouldClose = glfwWindowShouldClose(_hwnd);
    glfwPollEvents();
}

} // namespace Voxy::Platform
