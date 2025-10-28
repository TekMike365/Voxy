#pragma once

namespace Voxy {

class IGraphicsContext {
public:
    virtual void MakeCurrent() const = 0;
    virtual void SwapBuffers() const = 0;
};

} // namespace Voxy
