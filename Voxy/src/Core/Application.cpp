#include "Application.hpp"

#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "Log.hpp"
#include "Time.hpp"

#define BIND_APP_EVENT(fn)                                                     \
    std::bind(&Application::fn, this, std::placeholders::_1)

namespace Voxy {

Application *Application::s_Instance = nullptr;

Application::Application() : m_LayerStack("CoreUpdateStack") {
    VoxyAssert(!s_Instance, "There can oly be one instance of Application");
    s_Instance = this;

    m_Window = Voxy::Window::Create({.Callback = BIND_APP_EVENT(OnEvent)});
}

Application::~Application() { s_Instance = nullptr; }

void Application::Run() {
    VoxyCoreInfo("Main loop started");

    TimeStep deltaTime = 0;
    Time now, then = Time::Now();
    while (m_IsRunning) {
        BeginFrame();

        for (Layer *layer : m_LayerStack)
            layer->OnUpdate(deltaTime);

        for (Layer *layer : m_LayerStack)
            layer->OnRender();

        m_Window->Update(deltaTime);

        EndFrame();

        now = Time::Now();
        deltaTime = now - then;
        then = now;
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
    (void)e;
    VoxyCoreWarn("Shutting down");
    m_IsRunning = false;
    return true;
}

void Application::BeginFrame() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void Application::EndFrame() {
    m_Window->GetGraphicsContext()->GetRenderer()->Render();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

} // namespace Voxy
