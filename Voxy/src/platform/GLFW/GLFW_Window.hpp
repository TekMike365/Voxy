#pragma once

#include <GLFW/glfw3.h>

#include "Window.hpp"

namespace Voxy {

class GLFW_Window : public Window {
public:
    GLFW_Window(WindowParams &params);
    ~GLFW_Window();

    virtual void Update(TimeStep deltaTime) override;

    virtual uint32_t GetWidth() const override { return m_Params.width; }
    virtual uint32_t GetHeight() const override { return m_Params.height; }

    inline virtual Ref<GraphicsContext> GetGraphicsContext() const override {
        return m_GraphicsContext;
    }

private:
    WindowParams m_Params;
    GLFWwindow *m_HWND;
    Ref<GraphicsContext> m_GraphicsContext;
};

} // namespace Voxy
