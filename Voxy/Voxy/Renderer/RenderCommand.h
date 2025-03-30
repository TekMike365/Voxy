#pragma once

#include "Helpers.h"

namespace Voxy::Renderer
{
    class RenderCommand
    {
    public:
        virtual void DrawIndexed(size_t count, size_t pointer = 0) = 0;

        static Ref<RenderCommand> Create();
    };
}
