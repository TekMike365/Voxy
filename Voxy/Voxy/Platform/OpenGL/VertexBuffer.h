#pragma once

#include "Voxy/Graphics/VertexBuffer.h"

namespace Voxy::OpenGL
{
    class VertexBuffer : public Renderer::VertexBuffer
    {
    public:
        VertexBuffer(size_t size, const void *data);
        ~VertexBuffer();

        virtual void Bind() const override;
        virtual void Unbind() const override;

    private:
        uint32_t m_ID;
    };
}