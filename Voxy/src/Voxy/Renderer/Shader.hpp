#pragma once
#include <cstdint>

namespace Voxy::Renderer {

struct Shader { // TODO
public:
    inline uint32_t GetID() const { return _id; }

private:
    uint32_t _id;
};

} // namespace Voxy::Renderer
