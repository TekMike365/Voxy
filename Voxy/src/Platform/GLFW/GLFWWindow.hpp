#pragma once

#include "Window.hpp"
#include <GLFW/glfw3.h>

namespace Voxy::Platform {

class GLFWWindow : public IWindow {
public:
    GLFWWindow(const WindowParams &params);
    virtual ~GLFWWindow();

    virtual void Update() override;
    virtual inline bool ShouldClose() override { return _shouldClose; }

private:
    WindowParams _params;
    GLFWwindow *_hwnd;
    bool _shouldClose;
};

} // namespace Voxy::Platform
