#include "Application.h"

#include "Log.h"

#define BIND_APP_EVENT(fn) std::bind(&Application::fn, this, std::placeholders::_1)

namespace Voxy
{
    Application::Application()
    {
        m_Window = Window::CreateWindow();
        m_Window->SetEventCallback(BIND_APP_EVENT(OnEvent));
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        while (m_IsRunning)
        {
            // Render

            m_Window->OnUpdate();
        }
    }
    
    void Application::OnEvent(Event &e)
    {
        EventDispatcher d(e);
        d.Dispatch<WindowCloseEvent>(BIND_APP_EVENT(OnWindowClose));
    }

    bool Application::OnWindowClose(WindowCloseEvent &e)
    {
        VOXY_WARN("Closing window!");
        m_IsRunning = false;
        return true;
    }
}