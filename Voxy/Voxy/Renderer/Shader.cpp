#include "Shader.h"

#include "Voxy/Platform/OpenGL/Shader.h"

namespace Voxy::Renderer
{
    Ref<Shader> Shader::Create(const std::string &vertexSource, const std::string &fragmentSource)
    {
        return Ref<Shader>(new OpenGL::Shader(vertexSource, fragmentSource));
    }
}