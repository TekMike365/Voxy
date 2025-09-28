#pragma once

#include "Window.hpp"
#include <GLFW/glfw3.h>

namespace Voxy {

class GLFW_Window : public Window {
public:
    GLFW_Window(WindowParams &params);
    ~GLFW_Window();

    virtual uint32_t GetWidth() const override { return m_Params.width; }
    virtual uint32_t GetHeight() const override { return m_Params.height; }

    virtual void *GetHandle() const override { return (void *)m_Handle; }

private:
    WindowParams m_Params;
    GLFWwindow *m_Handle;
};

} // namespace Voxy
