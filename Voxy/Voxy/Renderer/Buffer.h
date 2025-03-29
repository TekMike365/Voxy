#pragma once

#include "Helpers.h"

namespace Voxy::Renderer
{
    enum class BufferType
    {
        None = 0,
        Vertex,
        Index
    };

    class Buffer
    {
    public:
        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual BufferType GetType() const = 0;

        // TODO: add usage
        static Ref<Buffer> Create(BufferType type, size_t size = 0, const void *data = nullptr);
    };
}
