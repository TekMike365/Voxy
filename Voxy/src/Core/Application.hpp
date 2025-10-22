#pragma once

#include "Helpers.hpp"

#include "Events/Event.hpp"
#include "Events/WindowEvents.hpp"
#include "Window.hpp"

#include "Layers/LayerStack.hpp"

namespace Voxy {

class Application {
public:
    Application();
    ~Application();

    void Run();

    template <typename T> inline void AddLayer() { m_LayerStack.AddLayer<T>(); }
    template <typename T> inline void AddOverlay() {
        m_LayerStack.AddOverlay<T>();
    }

    Ref<Window> GetWindow() { return m_Window; }

public:
    static Application *GetInstance() { return s_Instance; }

private:
    void OnEvent(Event &e);
    bool OnWindowClose(WindowCloseEvent &e);
    void BeginFrame();
    void EndFrame();

private:
    LayerStack m_LayerStack;
    Ref<Window> m_Window;
    bool m_IsRunning = true;

private:
    static Application *s_Instance;
};

} // namespace Voxy
