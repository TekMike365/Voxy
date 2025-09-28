#pragma once

#include "Layer.hpp"
#include <GLFW/glfw3.h>

namespace Voxy {

class RenderingLayer : public Layer {
public:
    virtual void OnUpdate() override {
        /* Render here */
        glClearColor(0.95f, 0.64f, 0.48f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

private:
    bool m_FirstLoop = true;
};

} // namespace Voxy