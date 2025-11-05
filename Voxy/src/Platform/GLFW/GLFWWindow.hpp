#pragma once

#include "GLFWGraphicsContext.hpp"
#include "Helpers.hpp"
#include "Window.hpp"
#include <GLFW/glfw3.h>
#include <imgui.h>

namespace Voxy::Platform {

class GLFWWindow : public IWindow {
public:
    GLFWWindow(const WindowParams &params);
    virtual ~GLFWWindow();

    virtual void Update() override;

    virtual inline bool ShouldClose() override { return m_ShouldClose; }
    virtual const WindowParams &GetParams() const override { return m_Params; }
    virtual inline const IGraphicsContext &GetContext() const override {
        return *m_Context;
    }

private:
    WindowParams m_Params;
    URef<GLFWGraphicsContext> m_Context;
    bool m_ShouldClose;
};

} // namespace Voxy::Platform
