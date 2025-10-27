#pragma once

namespace Voxy {

class IGraphicsContext {
public:
    virtual void MakeCurrent() const = 0;
    virtual void SwapBuffers() const = 0;

    virtual void BeginFrame() const = 0;
    virtual void EndFrame() const = 0;

    static inline const IGraphicsContext *GetCurrentContext() {
        return s_Current;
    }

protected:
    static const IGraphicsContext *s_Current;
};

} // namespace Voxy
