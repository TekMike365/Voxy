#include <GLFW/glfw3.h>

#include "Application.hpp"
#include "Setup.hpp"
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

static void glfw_error_callback(int error, const char *description) {
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

int main(void) {
    Voxy::Init();

    auto *app = new Voxy::Application;
    app->Run();
    delete app;

    Voxy::Terminate();
}
