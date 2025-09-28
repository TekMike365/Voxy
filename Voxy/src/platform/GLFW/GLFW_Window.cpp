#include "GLFW_Window.hpp"

#include "Events/WindowEvents.hpp"
#include "Log.hpp"
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace Voxy {

Ref<Window> Window::Create(WindowParams params) {
    return std::make_shared<GLFW_Window>(params);
}

GLFW_Window::GLFW_Window(WindowParams &params) : m_Params(params) {
    m_HWND = glfwCreateWindow(m_Params.width, m_Params.height, m_Params.title,
                              NULL, NULL);
    VoxyAssert(m_HWND, "GLFW: Couldn't create a window.");

    // TODO: Move???
    /* Make the window's context current */
    glfwMakeContextCurrent(m_HWND);
    glfwSwapInterval(1); // Enable vsync

    glfwSetWindowUserPointer(m_HWND, this);

    // Events
    glfwSetWindowCloseCallback(m_HWND, [](GLFWwindow *window) {
        GLFW_Window *wnd = (GLFW_Window *)glfwGetWindowUserPointer(window);

        WindowCloseEvent e;
        if (wnd->m_Params.Callback)
            wnd->m_Params.Callback(e);
    });

    // glfwSetFramebufferSizeCallback(
    //     m_Window, [](GLFWwindow *window, int width, int height) {
    //         Window *wnd = (Window *)glfwGetWindowUserPointer(window);
    //         wnd->m_Params.Width = width;
    //         wnd->m_Params.Height = height;

    //         WindowResizeEvent e(width, height);
    //         wnd->m_CallbackFn(e);
    //     });

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
    glfwDestroyWindow(m_HWND);

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void GLFW_Window::Update() {
    glfwPollEvents();

    // TODO: Move rendering out of this

    // Rendering
    ImGui::Render();
    glViewport(0, 0, m_Params.width, m_Params.height);

    /* Render here */
    glClearColor(0.95f, 0.64f, 0.48f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    /* Swap front and back buffers */
    glfwSwapBuffers(m_HWND);
}

} // namespace Voxy