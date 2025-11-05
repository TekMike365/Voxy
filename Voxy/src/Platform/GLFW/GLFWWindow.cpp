#include "GLFWWindow.hpp"

#include "Helpers.hpp"
#include "Log.hpp"
#include <cassert>

namespace Voxy::Platform {

GLFWWindow::GLFWWindow(const WindowParams &params)
    : m_Params(params), m_ShouldClose(false) {
    GLFWwindow *hwnd = glfwCreateWindow(m_Params.width, m_Params.height,
                                        m_Params.title.c_str(), NULL, NULL);

    glfwMakeContextCurrent(hwnd);
    glfwSwapInterval(1); // enable VSync (needs bound context)

    m_Context = std::make_unique<GLFWGraphicsContext>(hwnd);

    Log::Trace("GLFW window created: {} (0x{:x})", m_Params.title,
               (size_t)m_Context->m_Hwnd);
}

GLFWWindow::~GLFWWindow() {
    GLFWwindow *hwnd = m_Context->m_Hwnd;
    m_Context.reset(); // destroy context
    glfwDestroyWindow(hwnd);

    Log::Trace("GLFW window terminated: {} (0x{:x})", m_Params.title,
               (size_t)hwnd);
}

void GLFWWindow::Update() {
    m_ShouldClose = glfwWindowShouldClose(m_Context->m_Hwnd);
    glfwPollEvents();
}

} // namespace Voxy::Platform
