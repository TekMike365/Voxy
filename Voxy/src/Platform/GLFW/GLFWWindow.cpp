#include "GLFWWindow.hpp"

#include "Helpers.hpp"
#include "Log.hpp"
#include <cassert>

namespace Voxy::Platform {

GLFWWindow::GLFWWindow(const WindowParams &params)
    : _params(params), _shouldClose(false) {
    GLFWwindow *hwnd = glfwCreateWindow(_params.width, _params.height,
                                        _params.title.c_str(), NULL, NULL);

    glfwMakeContextCurrent(hwnd);
    glfwSwapInterval(1); // enable VSync (needs bound context)

    _context = std::make_unique<GLFWGraphicsContext>(hwnd);

    Log::Trace("GLFW window created: {} (0x{:x})", _params.title,
               (size_t)_context->_hwnd);
}

GLFWWindow::~GLFWWindow() {
    GLFWwindow *hwnd = _context->_hwnd;
    _context.reset(); // destroy context
    glfwDestroyWindow(hwnd);

    Log::Trace("GLFW window terminated: {} (0x{:x})", _params.title,
               (size_t)hwnd);
}

void GLFWWindow::Update() {
    _shouldClose = glfwWindowShouldClose(_context->_hwnd);
    glfwPollEvents();
}

} // namespace Voxy::Platform
