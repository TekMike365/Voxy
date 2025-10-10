#pragma once

#include <GLFW/glfw3.h>

#include "Core/Window.hpp"
#include "Log.hpp"

namespace Voxy::Platform::GLFW {

class Window : public Voxy::Window {
public:
    Window(WindowParams &params);
    ~Window();

    virtual void Update(TimeStep deltaTime) override;

    virtual uint32_t GetWidth() const override { return m_Params.width; }
    virtual uint32_t GetHeight() const override { return m_Params.height; }

    inline virtual Ref<Voxy::GraphicsContext>
    GetGraphicsContext() const override {
        return m_Params.graphicsContext;
    }

private:
    WindowParams m_Params;
    GLFWwindow *m_HWND;
};

} // namespace Voxy::Platform::GLFW
