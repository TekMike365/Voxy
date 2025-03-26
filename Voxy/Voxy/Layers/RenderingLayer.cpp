#include "RenderingLayer.h"

#include <glad/glad.h>

namespace Voxy
{
    void RenderingLayer::OnUpdate(TimeStep dt)
    {
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}