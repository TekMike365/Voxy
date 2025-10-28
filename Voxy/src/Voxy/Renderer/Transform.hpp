#pragma once

#include "Math/Math.hpp"

namespace Voxy::Renderer {
using namespace Math;

struct Transform { // TODO
    Vector3 position;
    Quaternion rotation;
    Vector3 scale;

    inline Matrix4 ToMat4() const { return Matrix4(position, rotation, scale); }
};

} // namespace Voxy::Renderer
