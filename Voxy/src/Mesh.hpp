#pragma once

#include <vector>

namespace Voxy {

template <typename Vert> struct Mesh {
    std::vector<Vert> vertices;
    std::vector<uint32_t> indices;
};

} // namespace Voxy
