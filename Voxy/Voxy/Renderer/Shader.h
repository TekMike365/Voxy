#pragma once

#include <string>
#include <glm/glm.hpp>

#include "Helpers.h"

namespace Voxy::Renderer
{
    class Shader
    {
    public:
        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual void UploadUniform(const glm::mat4 &mat, const std::string &name) const = 0;

        static Ref<Shader> Create(const std::string &vertexSource, const std::string &fragmentSource);
    };
}