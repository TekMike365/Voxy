#pragma once

#include <string>

namespace Voxy {

struct WindowParams {
    int width = 1280;
    int height = 720;
    std::string title = "Window";
};

class IWindow {
public:
    virtual void Update() = 0;
    virtual bool ShouldClose() = 0; // TODO: events
};

} // namespace Voxy
