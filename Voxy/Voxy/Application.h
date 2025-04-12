#pragma once

#include "Helpers.h"
#include "Window.h"
#include "Renderer/GraphicsContext.h"

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

        inline void PushLayer(const Ref<Layer> &layer) { m_LayerStack.PushLayer(layer); }
        inline void PushOverlay(const Ref<Layer> &overlay) { m_LayerStack.PushOverlay(overlay); }

    private:
        void OnEvent(Event &e);
        bool OnWindowClose(WindowCloseEvent &e);

    private:
        Ref<Window> m_Window;
        bool m_IsRunning = true;

        LayerStack m_LayerStack;

        static Application *s_Instance;
    };

    // To be defined in Client
    Application *CreateApplication();
}
