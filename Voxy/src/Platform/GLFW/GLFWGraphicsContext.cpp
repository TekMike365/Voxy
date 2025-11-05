#include "GLFWGraphicsContext.hpp"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace Voxy::Platform {

GLFWGraphicsContext::GLFWGraphicsContext(GLFWwindow *hwnd) : m_Hwnd(hwnd) {
    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(m_Hwnd, true);
    ImGui_ImplOpenGL3_Init("#version 130");
}

GLFWGraphicsContext::~GLFWGraphicsContext() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
}

inline void GLFWGraphicsContext::MakeCurrent() const {
    glfwMakeContextCurrent(m_Hwnd);
}

} // namespace Voxy::Platform
