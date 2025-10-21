#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

namespace Voxy {

struct Camera {
    // TODO: Ortho camera
    // TODO: Params access
    Camera(float fovy, float aspect, float near, float far) {
        SetParams(fovy, aspect, near, far);
    }

    inline void SetParams(float fovy, float aspect, float near, float far) {
        m_ProjMat = glm::perspective(fovy, aspect, near, far);
    }

    const glm::mat4 &GetProjection() { return m_ProjMat; };

private:
    glm::mat4 m_ProjMat;
};

} // namespace Voxy
