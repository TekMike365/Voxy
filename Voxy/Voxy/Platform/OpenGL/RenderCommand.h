#pragma once

#include "Voxy/Renderer/RenderCommand.h"

namespace Voxy::OpenGL
{
    class RenderCommand : public Renderer::RenderCommand
    {
    public:
        RenderCommand() = default;
        ~RenderCommand() = default;

        virtual void DrawIndexed(size_t indexCount, size_t indexPointer, size_t instanceCount) override;
    };
}
