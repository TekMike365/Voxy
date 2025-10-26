#include "GLFWWindow.hpp"

#include "Helpers.hpp"
#include "Log.hpp"
#include <cassert>

namespace Voxy::Platform {

GLFWWindow::GLFWWindow(const WindowParams &params)
    : _params(params), _shouldClose(false) {
    _hwnd = glfwCreateWindow(_params.width, _params.height,
                             _params.title.c_str(), NULL, NULL);
    assert(_hwnd);

    Log::Info("New GLFW window created: {}", _params.title);
}

GLFWWindow::~GLFWWindow() { glfwDestroyWindow(_hwnd); }

void GLFWWindow::Update() {
    _shouldClose = glfwWindowShouldClose(_hwnd);
    glfwSwapBuffers(_hwnd);
    glfwPollEvents();
}

void GLFWWindow::MakeContextCurrent() {
    glfwMakeContextCurrent(_hwnd); // TODO: less swaps
    glfwSwapInterval(1);           // enable VSync (needs bound context)
}

} // namespace Voxy::Platform
