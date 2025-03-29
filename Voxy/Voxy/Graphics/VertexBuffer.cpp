#include "VertexBuffer.h"

#include "Voxy/Platform/OpenGL/VertexBuffer.h"

namespace Voxy::Renderer
{
    Ref<VertexBuffer> VertexBuffer::Create(size_t size, const void *data)
    {
        return Ref<VertexBuffer>(new OpenGL::VertexBuffer(size, data));
    }
}
