#pragma once

#include <glm/glm.hpp>
#include <string>

#include "Helpers.hpp"

namespace Voxy::Renderer {

class Shader {
public:
    virtual ~Shader() = default;

    virtual void Bind() const = 0;
    virtual void Unbind() const = 0;

    virtual void UploadUniform(const glm::mat4 &mat,
                               const std::string &name) const = 0;

    virtual uint32_t GetID() const = 0;

public:
    static Ref<Shader> Create(const std::string &vertexSource,
                              const std::string &fragmentSource);
};

} // namespace Voxy::Renderer