#pragma once

#include "Math/Math.hpp"

namespace Voxy::Renderer {
using namespace Math;

struct Camera { // TODO
    Camera(float fovy, float aspect, float near, float far) {
        _projection = glm::perspective(fovy, aspect, near, far);
    }

    inline const Matrix4 &GetProjection() const { return _projection; }

private:
    Matrix4 _projection;
};

} // namespace Voxy::Renderer
