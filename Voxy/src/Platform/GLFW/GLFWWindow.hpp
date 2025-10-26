#pragma once

#include "Window.hpp"
#include <GLFW/glfw3.h>
#include <imgui.h>

namespace Voxy::Platform {

class GLFWWindow : public IWindow {
public:
    GLFWWindow(const WindowParams &params);
    virtual ~GLFWWindow();

    virtual void Update() override;
    virtual void MakeContextCurrent() override;
    virtual inline bool ShouldClose() override { return _shouldClose; }
    virtual const WindowParams &GetParams() const override { return _params; }

private:
    WindowParams _params;
    GLFWwindow *_hwnd;
    bool _shouldClose;

    ImGuiContext *_imGuiContext = nullptr; //? TMP
};

} // namespace Voxy::Platform
