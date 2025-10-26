#include <Voxy/Application.hpp>
#include <Voxy/Voxy.hpp>

int main(void) {
    Voxy::Init();

    auto *app = new Voxy::Application();
    app->Run();
    delete app;

    Voxy::Terminate();
}
