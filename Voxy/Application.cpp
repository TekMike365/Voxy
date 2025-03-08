#include "Application.h"

#include "Log.h"

namespace Voxy
{
    Application::Application()
    {
        m_Window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
        if (!m_Window)
        {
            VOXY_ERROR("Failed to crate window.");
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(m_Window);
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        while (!glfwWindowShouldClose(m_Window))
        {
            // Render

            // Swap front and back buffers
            glfwSwapBuffers(m_Window);

            // Poll for and process events
            glfwPollEvents();
        }

        glfwTerminate();
    }
}