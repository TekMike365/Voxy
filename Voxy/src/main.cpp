#include <GLFW/glfw3.h>

#include "Core/Application.hpp"
#include "Setup.hpp"

int main(void) {
    Voxy::Init();

    auto *app = new Voxy::Application;
    app->Run();
    delete app;

    Voxy::Terminate();
}
