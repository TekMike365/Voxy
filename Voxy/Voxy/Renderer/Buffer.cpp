#include "Buffer.h"

#include "Voxy/Platform/OpenGL/Buffer.h"

namespace Voxy::Renderer
{
    Ref<Buffer> Buffer::Create(BufferType type, size_t size, const void *data)
    {
        return Ref<Buffer>(new OpenGL::Buffer(type, size, data));
    }
}
