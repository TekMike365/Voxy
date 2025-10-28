#include "Platform.hpp"

#include "GLFW/GLFW.hpp"
#include "GLFW/GLFWWindow.hpp"
#include <cassert>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace Voxy::Platform {

void Init() { GLFWInit(); }

void Terminate() { GLFWTerminate(); }

Ref<IWindow> CreateWindow(const WindowParams &params) {
    return std::make_shared<GLFWWindow>(params);
}

void BeginImGuiFrame() {
    /*
        Needs to handle platform initializations and deinitializations to
        minimize performace loss (maybe idk)
     */
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
}

} // namespace Voxy::Platform
