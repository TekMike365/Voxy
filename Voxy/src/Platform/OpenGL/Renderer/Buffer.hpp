#pragma once

#include "Renderer/Buffer.hpp"

namespace Voxy::Renderer {

class OpenGL_Buffer : public Buffer {
public:
    OpenGL_Buffer(BufferType type, size_t size, const void *data);
    ~OpenGL_Buffer();

    virtual void Bind() const override;
    virtual void Unbind() const override;

    inline virtual BufferType GetType() const override { return m_Type; }
    virtual uint32_t GetID() const override { return m_ID; }

private:
    BufferType m_Type;
    uint32_t m_ID;
};

} // namespace Voxy::Renderer