#pragma once

#include <cstdint>
#include <unordered_map>

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

        virtual void UploadUniform(const glm::mat4 &mat, const std::string &name) const override;

    private:
        uint32_t m_ID;
        std::unordered_map<std::string, int32_t> m_UniformLocationMap;
    };
}
