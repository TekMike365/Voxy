#pragma once

#include "Helpers.hpp"
#include "Window.hpp"

namespace Voxy {

class Application {
public:
    Application();
    ~Application();

    void Run();
    void Quit();

private:
    void BeginFrame();

private:
    bool _running;
    Ref<IWindow> _window;
};

} // namespace Voxy
