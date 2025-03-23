#pragma once

#include <glad/glad.h> // TODO: Remove
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

        inline virtual void *GetWindowHandle() const override { return m_Window; };

        inline virtual void SetEventCallback(CallbackFn callback) override { m_CallbackFn = callback; }

    private:
        GLFWwindow *m_Window;
        WindowParams m_Params;
        CallbackFn m_CallbackFn;
    };
}
