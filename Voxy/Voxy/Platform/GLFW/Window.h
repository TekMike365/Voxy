#pragma once

#include <GLFW/glfw3.h>

#include "Voxy/IWindow.h"

namespace Voxy::GLFW
{
    class Window : public Voxy::IWindow
    {
    public:
        Window(const WindowParams &params);
        ~Window();

        virtual void OnUpdate() override;

        virtual void InitImGui() override;
        inline virtual void SetGraphicsContext(const Ref<IGraphicsContext> &context) override { m_GraphicsContext = context; }
        inline virtual void SetEventCallback(CallbackFn callback) override { m_CallbackFn = callback; }

        inline virtual void *GetWindowHandle() const override { return m_Window; };
        inline virtual const WindowParams &GetParams() const override { return m_Params; }

    private:
        GLFWwindow *m_Window;
        WindowParams m_Params;
        CallbackFn m_CallbackFn;
        Ref<IGraphicsContext> m_GraphicsContext;
        bool m_ImGuiInitialised = false;
    };
}
