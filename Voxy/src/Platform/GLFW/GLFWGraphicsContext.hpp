#pragma once

#include "GraphicsContext.hpp"
#include <GLFW/glfw3.h>
#include <imgui.h>

namespace Voxy::Platform {

class GLFWGraphicsContext : public IGraphicsContext {
    friend class GLFWWindow;

public:
    GLFWGraphicsContext(GLFWwindow *hwnd);
    virtual ~GLFWGraphicsContext();

    virtual inline void MakeCurrent() const override;
    virtual inline void SwapBuffers() const override {
        glfwSwapBuffers(m_Hwnd);
    }

private:
    GLFWwindow *m_Hwnd;
};

} // namespace Voxy::Platform
