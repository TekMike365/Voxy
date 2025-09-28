#include "Application.hpp"

#include "Log.hpp"

#define BIND_APP_EVENT(fn)                                                     \
    std::bind(&Application::fn, this, std::placeholders::_1)

namespace Voxy {

Application::Application() {

    auto wnd = Voxy::Window::Create({.Callback = BIND_APP_EVENT(OnEvent)});

    while (m_IsRunning) {
        wnd->Update();
    }
}
Application::~Application() {}

void Application::Run() {}

void Application::OnEvent(Event &e) {
    EventDispatcher d(e);
    d.Dispatch<Voxy::WindowCloseEvent>(BIND_APP_EVENT(OnWindowClose));
}

bool Application::OnWindowClose(WindowCloseEvent &e) {
    VoxyCoreWarn("Shutting down");
    m_IsRunning = false;
    return true;
}

} // namespace Voxy
