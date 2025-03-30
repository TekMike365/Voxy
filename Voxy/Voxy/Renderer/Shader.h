#pragma once

#include <string>

#include "Helpers.h"

namespace Voxy::Renderer
{
    class Shader
    {
    public:
        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        static Ref<Shader> Create(const std::string &vertexSource, const std::string &fragmentSource);
    };
}