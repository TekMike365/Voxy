#pragma once

#include <GLFW/glfw3.h>

#include "Window.hpp"

namespace Voxy {

class GLFW_Window : public Window {
public:
    GLFW_Window(WindowParams &params);
    ~GLFW_Window();

    virtual void Update() override;

    virtual uint32_t GetWidth() const override { return m_Params.width; }
    virtual uint32_t GetHeight() const override { return m_Params.height; }

    virtual void *GetHandle() const override { return (void *)m_HWND; }

private:
    WindowParams m_Params;
    GLFWwindow *m_HWND;
};

} // namespace Voxy
