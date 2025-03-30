#pragma once

#include "Helpers.h"

namespace Voxy::Renderer
{
    class RenderCommand
    {
    public:
        virtual void DrawIndexed(size_t indexCount, size_t indexPointer=0, size_t instanceCount=1) = 0;

        static Ref<RenderCommand> Create();
    };
}
