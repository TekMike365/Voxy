#pragma once

#include "Helpers.h"
#include "IWindow.h"
#include "Renderer/IGraphicsContext.h"

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

        static Application *Get() { return s_Instance; }

    private:
        void OnEvent(Event &e);
        bool OnWindowClose(WindowCloseEvent &e);

    private:
        Ref<IWindow> m_Window;
        Ref<IGraphicsContext> m_GraphicsContext;
        bool m_IsRunning = true;

        LayerStack m_LayerStack;

        static Application *s_Instance;
    };

    // To be defined in Client
    Application *CreateApplication();
}
