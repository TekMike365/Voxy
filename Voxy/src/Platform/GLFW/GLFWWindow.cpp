#include "GLFWWindow.hpp"

#include <Log.hpp>
#include <cassert>

namespace Voxy::Platform {

GLFWWindow::GLFWWindow(const WindowParams &params)
    : _params(params), _shouldClose(false) {
    _hwnd = glfwCreateWindow(_params.width, _params.height,
                             _params.title.c_str(), NULL, NULL);
    assert(_hwnd);

    Log::Info("New GLFW window created: {}", _params.title);

    glfwSwapInterval(1); // enable VSync
}

GLFWWindow::~GLFWWindow() { glfwDestroyWindow(_hwnd); }

void GLFWWindow::Update() {
    glfwMakeContextCurrent(_hwnd); // TODO: less swaps
    _shouldClose = glfwWindowShouldClose(_hwnd);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(_hwnd);
    glfwPollEvents();
}

} // namespace Voxy::Platform
