#pragma once

#include "Voxy/Renderer/Buffer.h"

namespace Voxy::OpenGL
{
    class Buffer : public Renderer::Buffer
    {
        using BufferType = Renderer::BufferType;

    public:
        Buffer(BufferType type, size_t size, const void *data);
        ~Buffer();

        virtual void Bind() const override;
        virtual void Unbind() const override;

        inline virtual BufferType GetType() const override { return m_Type; }

    private:
        BufferType m_Type;
        uint32_t m_ID;
    };
}