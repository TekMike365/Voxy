#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

namespace Voxy {

struct Transform {
    glm::vec3 pos;
    glm::vec3 scale;
    glm::quat rot;

    Transform() : pos(), scale(1), rot() {}

    inline void Translate(const glm::vec3 &p) { pos += p; }
    inline void Scale(const glm::vec3 &s) { scale += s; }
    inline void Rotate(const glm::quat &q) { rot = rot * q; }

    inline glm::mat4 ToMat4() const {
        glm::mat4 mat = glm::mat4_cast(rot);
        mat = glm::scale(mat, scale);
        mat = glm::translate(mat, pos);
        return mat;
    }
};

} // namespace Voxy
