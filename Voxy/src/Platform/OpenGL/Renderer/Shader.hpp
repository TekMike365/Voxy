#pragma once

#include <cstdint>
#include <unordered_map>

#include "Renderer/Shader.hpp"

namespace Voxy::Renderer {

class OpenGL_Shader : public Shader {
public:
    OpenGL_Shader(const std::string &vertexSource,
                  const std::string &fragmentSource);
    ~OpenGL_Shader();

    virtual void Bind() const override { SBind(m_ID); }
    virtual void Unbind() const override { SUnbind(); }

    virtual void UploadUniform(const glm::mat4 &mat,
                               const std::string &name) const override;

    virtual uint32_t GetID() const override { return m_ID; }

public:
    static void SBind(uint32_t id);
    static void SUnbind() { SBind(0); }

private:
    uint32_t m_ID;
    std::unordered_map<std::string, int32_t> m_UniformLocationMap;
};

} // namespace Voxy::Renderer
