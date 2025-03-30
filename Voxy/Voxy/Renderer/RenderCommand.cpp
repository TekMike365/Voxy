#include "RenderCommand.h"

#include "Voxy/Platform/OpenGL/RenderCommand.h"

namespace Voxy::Renderer
{
    Ref<RenderCommand> RenderCommand::Create()
    {
        return Ref<RenderCommand>(new OpenGL::RenderCommand());
    }
}
