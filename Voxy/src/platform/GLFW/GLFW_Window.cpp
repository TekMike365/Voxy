#include "GLFW_Window.hpp"

#include "Log.hpp"

namespace Voxy {

Ref<Window> Window::Create(WindowParams params) {
    return std::make_shared<GLFW_Window>(params);
}

GLFW_Window::GLFW_Window(WindowParams &params) : m_Params(params) {
    m_Handle = glfwCreateWindow(m_Params.width, m_Params.height, m_Params.title,
                                NULL, NULL);
    VoxyAssert(m_Handle, "GLFW: Couldn't create a window.");
}

GLFW_Window::~GLFW_Window() {}

} // namespace Voxy