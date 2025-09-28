#pragma once

#include "Events/Event.hpp"
#include "Events/WindowEvents.hpp"
#include "Helpers.hpp"
#include "Layers/LayerStack.hpp"
#include "Window.hpp"

namespace Voxy {

class Application {
public:
    Application();
    ~Application();

    void Run();

    Ref<Window> GetWindow() { return m_Window; }

public:
    static Application *GetInstance() { return s_Instance; }

private:
    void OnEvent(Event &e);
    bool OnWindowClose(WindowCloseEvent &e);

private:
    LayerStack m_LayerStack;
    Ref<Window> m_Window;
    bool m_IsRunning = true;

private:
    static Application *s_Instance;
};

} // namespace Voxy
