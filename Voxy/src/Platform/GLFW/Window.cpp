#include "Window.hpp"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "Events/WindowEvents.hpp"
#include "Log.hpp"

namespace Voxy {

Ref<Window> Window::Create(WindowParams params) {
    return std::make_shared<Platform::GLFW_Window>(params);
}

namespace Platform {

GLFW_Window::GLFW_Window(WindowParams &params) : m_Params(params) {
    VoxyCoreTrace("Creating window. Using GLFW");

    m_HWND = glfwCreateWindow(m_Params.width, m_Params.height, m_Params.title,
                              NULL, NULL);
    VoxyAssert(m_HWND, "GLFW: Couldn't create a window.");

    // TODO: Move???
    /* Make the window's context current */
    glfwMakeContextCurrent(m_HWND);
    glfwSwapInterval(1); // Enable vsync

    m_Params.graphicsContext = GraphicsContext::Create();

    glfwSetWindowUserPointer(m_HWND, this);

    // Events
    glfwSetWindowCloseCallback(m_HWND, [](GLFWwindow *window) {
        GLFW_Window *wnd = (GLFW_Window *)glfwGetWindowUserPointer(window);

        WindowCloseEvent e;
        if (wnd->m_Params.Callback)
            wnd->m_Params.Callback(e);
    });

    glfwSetFramebufferSizeCallback(
        m_HWND, [](GLFWwindow *window, int width, int height) {
            GLFW_Window *wnd = (GLFW_Window *)glfwGetWindowUserPointer(window);
            wnd->m_Params.width = width;
            wnd->m_Params.height = height;

            wnd->m_Params.graphicsContext->SetViewport(0, 0, width, height);

            WindowResizeEvent e(width, height);
            if (wnd->m_Params.Callback)
                wnd->m_Params.Callback(e);
        });

    /*
        Dear ImGui stuff
    */

    // Setup Dear ImGui context
    ImGui::CreateContext();

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(m_HWND, true);
    ImGui_ImplOpenGL3_Init("#version 130");
}

GLFW_Window::~GLFW_Window() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(m_HWND);
}

void GLFW_Window::Update(TimeStep deltaTime) {
    (void)deltaTime;

    glfwPollEvents();
    glfwSwapBuffers(m_HWND);
}

} // namespace Platform
} // namespace Voxy