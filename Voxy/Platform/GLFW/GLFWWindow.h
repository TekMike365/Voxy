#pragma once

#include <GLFW/glfw3.h>

#include "Window.h"

namespace Voxy::GLFW
{
    class Window : public Voxy::Window
    {
    public:
        Window(const WindowParams &params);
        ~Window();

        virtual void OnUpdate() override;
        virtual bool ShouldClose() override;

    private:
        GLFWwindow *m_Window;
        WindowParams m_Params;
    };
}
