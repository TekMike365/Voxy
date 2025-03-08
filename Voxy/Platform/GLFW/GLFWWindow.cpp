#include "GLFWWindow.h"

#include "Log.h"

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

        // TODO: Move
        glfwMakeContextCurrent(m_Window);
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
    
    bool Window::ShouldClose()
    {
        return glfwWindowShouldClose(m_Window);
    }
}
