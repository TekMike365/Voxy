#include "Application.hpp"

#include "Layers/GUILayer.hpp"
#include "Layers/RenderingLayer.hpp"
#include "Layers/TestLayer.hpp"
#include "Log.hpp"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#define BIND_APP_EVENT(fn)                                                     \
    std::bind(&Application::fn, this, std::placeholders::_1)

namespace Voxy {

Application *Application::s_Instance = nullptr;

Application::Application() {
    VoxyAssert(!s_Instance, "There can oly be one instance of Application");
    s_Instance = this;

    m_Window = Voxy::Window::Create({.Callback = BIND_APP_EVENT(OnEvent)});

    m_LayerStack.PushOverlay(new RenderingLayer);
    m_LayerStack.PushOverlay(new GUILayer);
    m_LayerStack.PushLayer(new TestLayer);
}

Application::~Application() {}

void Application::Run() {
    VoxyCoreInfo("Main loop started");
    while (m_IsRunning) {
        for (Layer *layer : m_LayerStack)
            layer->OnUpdate();

        m_Window->Update();
    }
}

void Application::OnEvent(Event &e) {
    EventDispatcher d(e);

    bool handled =
        d.Dispatch<Voxy::WindowCloseEvent>(BIND_APP_EVENT(OnWindowClose));

    if (handled)
        return;

    for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); it++)
        if ((*it)->OnEvent(e))
            break;
}

bool Application::OnWindowClose(WindowCloseEvent &e) {
    VoxyCoreWarn("Shutting down");
    m_IsRunning = false;
    return true;
}

} // namespace Voxy
