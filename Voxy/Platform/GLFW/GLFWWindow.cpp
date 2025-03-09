#include "GLFWWindow.h"

#include "Log.h"
#include "Events/WindowEvent.h"

Ref<Voxy::Window> Voxy::Window::CreateWindow(const WindowParams &params)
{
    return Ref<Window>(new GLFW::Window(params));
}

namespace Voxy::GLFW
{
    Window::Window(const WindowParams &params)
        : m_Params(params)
    {
        m_Window = glfwCreateWindow(m_Params.Width, m_Params.Height, m_Params.Title.c_str(), NULL, NULL);
        if (!m_Window)
            VOXY_ERROR("Failed to crate window.");

        glfwSetWindowUserPointer(m_Window, this);

        // TODO: Move
        glfwMakeContextCurrent(m_Window);

        // Events
        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow *window){
            Window *wnd = (Window *)glfwGetWindowUserPointer(window);

            WindowCloseEvent e;
            wnd->m_CallbackFn(e);
        });
    }

    Window::~Window()
    {
        glfwDestroyWindow(m_Window);
    }

    void Window::OnUpdate()
    {
        // TODO: Move
        // Swap front and back buffers
        glfwSwapBuffers(m_Window);

        // Poll for and process events
        glfwPollEvents();
    }
}
