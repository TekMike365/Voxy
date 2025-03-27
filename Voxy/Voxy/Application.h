#pragma once

#include "Helpers.h"
#include "IWindow.h"

#include "Events/WindowEvent.h"
#include "Layers/LayerStack.h"

namespace Voxy
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

    private:
        void OnEvent(Event &e);
        bool OnWindowClose(WindowCloseEvent &e);

    private:
        Ref<IWindow> m_Window;
        bool m_IsRunning = true;

        LayerStack m_LayerStack;
    };

    // To be defined in Client
    Application *CreateApplication();
}
