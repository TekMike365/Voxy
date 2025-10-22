#include <Core/Application.hpp>
#include <Setup.hpp>

#include "TestLayer.hpp"

int main(void) {
    Voxy::Init();

    auto *app = new Voxy::Application;

    app->PushLayer(new TestLayer());

    app->Run();
    delete app;

    Voxy::Terminate();
}
