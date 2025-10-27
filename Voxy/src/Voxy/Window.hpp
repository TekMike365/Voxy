#pragma once

#include "GraphicsContext.hpp"
#include "Helpers.hpp"
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
    virtual const WindowParams &GetParams() const = 0;
    virtual const IGraphicsContext &GetContext() const = 0;
};

} // namespace Voxy
