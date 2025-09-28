#pragma once

#include "Helpers.hpp"

namespace Voxy {

struct WindowParams {
    const char *title = "Title";
    uint32_t width = 1280;
    uint32_t height = 720;
};

class Window {
public:
    virtual uint32_t GetWidth() const = 0;
    virtual uint32_t GetHeight() const = 0;
    virtual float GetAspect() const { return GetWidth() / GetHeight(); }

    virtual void *GetHandle() const = 0;

public:
    static Ref<Window> Create(WindowParams params = WindowParams());
};

} // namespace Voxy
