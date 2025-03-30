#pragma once

#include "Voxy/Renderer/RenderCommand.h"

namespace Voxy::OpenGL
{
    class RenderCommand : public Renderer::RenderCommand
    {
    public:
        RenderCommand() = default;
        ~RenderCommand() = default;

        virtual void DrawIndexed(size_t count, size_t pointer = 0) override;
    };
}
