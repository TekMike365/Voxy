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

    virtual inline bool ShouldClose() override { return _shouldClose; }
    virtual const WindowParams &GetParams() const override { return _params; }
    virtual inline const IGraphicsContext &GetContext() const override {
        return *_context;
    }

private:
    WindowParams _params;
    URef<GLFWGraphicsContext> _context;
    bool _shouldClose;
};

} // namespace Voxy::Platform
