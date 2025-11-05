#pragma once

#include "Math/Math.hpp"

namespace Voxy::Renderer {
using namespace Math;

struct Camera { // TODO
    Camera(float fovy, float aspect, float near, float far) {
        m_Projection = glm::perspective(fovy, aspect, near, far);
    }

    inline const Matrix4 &GetProjection() const { return m_Projection; }

private:
    Matrix4 m_Projection;
};

} // namespace Voxy::Renderer
