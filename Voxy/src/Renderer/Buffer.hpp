#pragma once

#include "Helpers.hpp"

namespace Voxy::Renderer {

enum class BufferType { None = 0, Vertex, Index };

class Buffer {
public:
    virtual void Bind() const = 0;
    virtual void Unbind() const = 0;

    virtual BufferType GetType() const = 0;
    virtual uint32_t GetID() const = 0;

public:
    static Ref<Buffer> Create(BufferType type, size_t size,
                              const void *data = nullptr);
};

} // namespace Voxy::Renderer