#include "Window.h"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "Log.h"
#include "Voxy/Events/WindowEvent.h"
#include "Voxy/Graphics/GraphicsContext.h"

namespace Voxy::GLFW
{
    Window::Window(const WindowParams &params)
        : m_Params(params)
    {
        m_Window = glfwCreateWindow(m_Params.Width, m_Params.Height, m_Params.Title.c_str(), NULL, NULL);
        VOXY_ASSERT(m_Window, "Failed to crate window.")

        glfwSetWindowUserPointer(m_Window, this);

        m_GraphicsContext = GraphicsContext::CreateContext(GraphicsAPI::OpenGL, m_Window);
        m_GraphicsContext->MakeCurrent();

        // Events
        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow *window)
                                   {
            Window *wnd = (Window *)glfwGetWindowUserPointer(window);

            WindowCloseEvent e;
            wnd->m_CallbackFn(e); });

        glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow *window, int width, int height)
                                       {
            Window *wnd = (Window *)glfwGetWindowUserPointer(window);
            wnd->m_Params.Width = width;
            wnd->m_Params.Height = height;

            WindowResizeEvent e(width, height);
            wnd->m_CallbackFn(e); });

        // ? move
        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        // ImGui::StyleColorsLight();

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
        ImGui_ImplOpenGL3_Init("#version 430 core");
    }

    Window::~Window()
    {
        // ? Move
        // Cleanup
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        glfwDestroyWindow(m_Window);
    }

    void Window::OnUpdate()
    {
        glfwPollEvents();
        if (glfwGetWindowAttrib(m_Window, GLFW_ICONIFIED) != 0)
        {
            ImGui_ImplGlfw_Sleep(10);
            return;
        }

        m_GraphicsContext->SwapBuffers();
        m_GraphicsContext->SetViewport(0, 0, m_Params.Width, m_Params.Height);
    }
}
