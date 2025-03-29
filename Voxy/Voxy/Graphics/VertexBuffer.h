#pragma once

#include "Helpers.h"

namespace Voxy::Renderer
{
    class VertexBuffer
    {
    public:
        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        // TODO: add usage
        static Ref<VertexBuffer> Create(size_t size = 0, const void *data = nullptr);
    };
}
