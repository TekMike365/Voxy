#include "RenderCommand.h"

#include <glad/glad.h>

namespace Voxy::OpenGL
{
    void RenderCommand::DrawIndexed(size_t indexCount, size_t indexPointer, size_t instanceCount)
    {
        if (instanceCount == 1)
            glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, (void *)indexPointer);
        else
            glDrawElementsInstanced(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, (void *)indexPointer, instanceCount);
    }
}