#pragma once
#include <cstdint>

namespace Voxy::Renderer {

struct Shader { // TODO
public:
    inline uint32_t GetID() const { return m_ID; }

private:
    uint32_t m_ID;
};

} // namespace Voxy::Renderer
