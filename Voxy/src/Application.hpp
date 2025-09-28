#pragma once

#include "Events/Event.hpp"
#include "Events/WindowEvents.hpp"
#include "Helpers.hpp"
#include "Window.hpp"

namespace Voxy {

class Application {
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

} // namespace Voxy
