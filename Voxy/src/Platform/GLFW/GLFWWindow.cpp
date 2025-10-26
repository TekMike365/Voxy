#include "GLFWWindow.hpp"

#include "Helpers.hpp"
#include "Log.hpp"
#include <cassert>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace Voxy::Platform {

GLFWWindow::GLFWWindow(const WindowParams &params)
    : _params(params), _shouldClose(false) {
    _hwnd = glfwCreateWindow(_params.width, _params.height,
                             _params.title.c_str(), NULL, NULL);
    assert(_hwnd);

    glfwMakeContextCurrent(_hwnd);
    glfwSwapInterval(1); // enable VSync (needs bound context)

    Log::Trace("GLFW window created: {} (0x{:x})", _params.title,
               (size_t)_hwnd);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();

    _imGuiContext = ImGui::CreateContext();
    ImGui::SetCurrentContext(_imGuiContext);

    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |=
        ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    io.ConfigFlags |=
        ImGuiConfigFlags_NavEnableGamepad; // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    // ImGui::StyleColorsLight();

    // Setup scaling
    float main_scale =
        ImGui_ImplGlfw_GetContentScaleForMonitor(glfwGetPrimaryMonitor());

    ImGuiStyle &style = ImGui::GetStyle();
    style.ScaleAllSizes(
        main_scale); // Bake a fixed style scale. (until we have a solution for
                     // dynamic style scaling, changing this requires resetting
                     // Style + calling this again)
    style.FontScaleDpi =
        main_scale; // Set initial font scale. (using
                    // io.ConfigDpiScaleFonts=true makes this unnecessary. We
                    // leave both here for documentation purpose)

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(_hwnd, true);
    ImGui_ImplOpenGL3_Init("#version 130");
}

GLFWWindow::~GLFWWindow() {
    auto *context = ImGui::GetCurrentContext();
    ImGui::SetCurrentContext(_imGuiContext);

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext(_imGuiContext);

    glfwDestroyWindow(_hwnd);

    ImGui::SetCurrentContext(context);

    Log::Trace("GLFW window terminated: {} (0x{:x})", _params.title,
               (size_t)_hwnd);
}

void GLFWWindow::Update() {
    _shouldClose = glfwWindowShouldClose(_hwnd);
    glfwSwapBuffers(_hwnd);
    glfwPollEvents();
}

void GLFWWindow::MakeContextCurrent() {
    glfwMakeContextCurrent(_hwnd);
    ImGui::SetCurrentContext(_imGuiContext);
}

} // namespace Voxy::Platform
