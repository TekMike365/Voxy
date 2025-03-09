#pragma once

#include "Helpers.h"
#include "Window.h"

#include "Events/WindowEvent.h"

namespace Voxy
{
    class Application
    {
    public:
        Application();
        ~Application();

        void Run();

    private:
        void OnEvent(Event &e);
        bool OnWindowClose(WindowCloseEvent &e);

    private:
        Ref<Window> m_Window;
        bool m_IsRunning = true;
    };
}
