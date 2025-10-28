#pragma once

#include <cstdint>
#include <vector>

namespace Voxy::Renderer {

struct IVertexData {};

struct IVertex { // TODO
    virtual const IVertexData &GetData() const = 0;
};

struct Mesh {
    std::vector<IVertex> vertices;
    std::vector<uint32_t> indices;
};

} // namespace Voxy::Renderer
