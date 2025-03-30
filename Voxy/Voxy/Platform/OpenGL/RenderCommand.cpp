#include "RenderCommand.h"

#include <glad/glad.h>

namespace Voxy::OpenGL
{
    void RenderCommand::DrawIndexed(size_t count, size_t pointer)
    {
        glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, (void *)pointer);
    }
}