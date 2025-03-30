#pragma once

#include <GLFW/glfw3.h>

#include "Voxy/Window.h"

namespace Voxy::GLFW
{
    class Window : public Voxy::Window
    {
    public:
        Window(const WindowParams &params);
        ~Window();

        virtual void OnUpdate() override;

        inline virtual void SetEventCallback(CallbackFn callback) override { m_CallbackFn = callback; }

        inline virtual void *GetWindowHandle() const override { return m_Window; };
        inline virtual const WindowParams &GetParams() const override { return m_Params; }
        inline virtual float GetAspect() const { return m_Params.Width / m_Params.Height; }

    private:
        GLFWwindow *m_Window;
        WindowParams m_Params;
        CallbackFn m_CallbackFn;
        Ref<GraphicsContext> m_GraphicsContext;
    };
}
