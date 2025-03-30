#pragma once

#include "Voxy/Renderer/Shader.h"

namespace Voxy::OpenGL
{
    class Shader : public Renderer::Shader
    {
    public:
        Shader(const std::string &vertexSource, const std::string &fragmentSource);
        ~Shader();

        virtual void Bind() const override;
        virtual void Unbind() const override;
    
    private:
        uint32_t m_ID;
    };
}
