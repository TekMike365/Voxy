#pragma once

#include "Voxy/Renderer/Buffer.h"

namespace Voxy::OpenGL
{
    class Buffer : public Renderer::Buffer
    {
    public:
        Buffer(Renderer::BufferType type, size_t size, const void *data);
        ~Buffer();

        virtual void Bind() const override;
        virtual void Unbind() const override;

        inline virtual Renderer::BufferType GetType() const override { return m_Type; }

    private:
        Renderer::BufferType m_Type;
        uint32_t m_ID;
    };
}