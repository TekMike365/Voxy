#include "Application.h"

#include "Log.h"

namespace Voxy
{
    Application::Application()
    {
        m_Window = Window::CreateWindow();
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        while (!m_Window->ShouldClose())
        {
            // Render

            m_Window->OnUpdate();
        }
    }
}