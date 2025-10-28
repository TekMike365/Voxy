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

    static Application &Get() { return *s_Instance; }

private:
    bool _running;
    Ref<IWindow> _window;

    static Application *s_Instance;
};

} // namespace Voxy
