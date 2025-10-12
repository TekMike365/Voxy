#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "Renderer/Mesh.hpp"

namespace Voxy::Renderer {

class OpenGL_Mesh : public IMesh {
public:
    OpenGL_Mesh(const Ref<IBuffer> &indexBuffer);
    ~OpenGL_Mesh();

    virtual void Bind() const override;
    virtual void Unbind() const override;

    virtual void AddObject(size_t pointer, size_t indexCount,
                           const std::string &name) override;
    virtual Object &GetObject(const std::string &name) override;
    virtual void AddAttribute(const VertexAttribute &attrib) override;

    inline virtual const Ref<IBuffer> &GetIndexBuffer() const override {
        return m_IndexBuffer;
    }
    virtual uint32_t GetID() const override { return m_ID; }

private:
    uint32_t m_ID;
    Ref<IBuffer> m_IndexBuffer;
    std::unordered_map<std::string, Object> m_Objects;
};

} // namespace Voxy::Renderer