#include "GLFWWindow.h"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "Log.h"
#include "Voxy/Events/WindowEvent.h"

namespace Voxy::GLFW
{
    Window::Window(const WindowParams &params)
        : m_Params(params)
    {
        m_Window = glfwCreateWindow(m_Params.Width, m_Params.Height, m_Params.Title.c_str(), NULL, NULL);
        if (!m_Window)
            VOXY_CORE_ERROR("Failed to crate window.");

        glfwSetWindowUserPointer(m_Window, this);

        // TODO: Move
        glfwMakeContextCurrent(m_Window);

        // TODO: Move
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            VOXY_CORE_ERROR("Glad couldn't be initialised.");

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

        //? Move
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
        //? Move
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

        // TODO: Move
        // Swap front and back buffers
        glfwSwapBuffers(m_Window);
        glViewport(0, 0, m_Params.Width, m_Params.Height);
    }
}
