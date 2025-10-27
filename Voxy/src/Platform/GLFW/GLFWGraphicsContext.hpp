#pragma once

#include "GraphicsContext.hpp"
#include <GLFW/glfw3.h>
#include <imgui.h>

namespace Voxy::Platform {

class GLFWGraphicsContext : public IGraphicsContext {
public:
    GLFWGraphicsContext(GLFWwindow *hwnd);
    virtual ~GLFWGraphicsContext();

    virtual inline void MakeCurrent() const override;
    virtual inline void SwapBuffers() const override { glfwSwapBuffers(_hwnd); }

    virtual void BeginFrame() const override;
    virtual void EndFrame() const override;

private:
    ImGuiContext *_imGuiContext;
    GLFWwindow *_hwnd;
};

} // namespace Voxy::Platform
