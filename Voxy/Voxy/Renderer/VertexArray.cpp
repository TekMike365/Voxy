#include "VertexArray.h"

#include "Voxy/Platform/OpenGL/VertexArray.h"

namespace Voxy::Renderer
{
    Ref<VertexArray> VertexArray::Create(const Ref<Buffer> &indexBuffer)
    {
        return Ref<VertexArray>(new OpenGL::VertexArray(indexBuffer));
    }
}
