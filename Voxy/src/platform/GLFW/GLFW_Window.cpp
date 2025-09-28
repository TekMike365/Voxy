#include "GLFW_Window.hpp"

#include "Events/WindowEvents.hpp"
#include "Log.hpp"

namespace Voxy {

Ref<Window> Window::Create(WindowParams params) {
    return std::make_shared<GLFW_Window>(params);
}

GLFW_Window::GLFW_Window(WindowParams &params) : m_Params(params) {
    m_WNDH = glfwCreateWindow(m_Params.width, m_Params.height, m_Params.title,
                              NULL, NULL);
    VoxyAssert(m_WNDH, "GLFW: Couldn't create a window.");

    glfwSetWindowUserPointer(m_WNDH, this);

    // Events
    glfwSetWindowCloseCallback(m_WNDH, [](GLFWwindow *window) {
        GLFW_Window *wnd = (GLFW_Window *)glfwGetWindowUserPointer(window);

        WindowCloseEvent e;
        if (wnd->m_Params.Callback)
            wnd->m_Params.Callback(e);
    });

    // glfwSetFramebufferSizeCallback(
    //     m_Window, [](GLFWwindow *window, int width, int height) {
    //         Window *wnd = (Window *)glfwGetWindowUserPointer(window);
    //         wnd->m_Params.Width = width;
    //         wnd->m_Params.Height = height;

    //         WindowResizeEvent e(width, height);
    //         wnd->m_CallbackFn(e);
    //     });
}

GLFW_Window::~GLFW_Window() { glfwDestroyWindow(m_WNDH); }

} // namespace Voxy