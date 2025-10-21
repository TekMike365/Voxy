#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/matrix_decompose.hpp>
#undef GLM_ENABLE_EXPERIMENTAL

namespace Voxy {

struct Transform {
    glm::vec3 pos;
    glm::vec3 scale;
    glm::quat rot;

    Transform() : pos(), scale(1), rot() {}
    Transform(const glm::vec3 &pos, const glm::vec3 &scale,
              const glm::quat &rot)
        : pos(pos), scale(scale), rot(rot) {}
    Transform(const glm::mat4 &t) {
        glm::vec3 skew;
        glm::vec4 perspective;
        glm::decompose(t, scale, rot, pos, skew, perspective);
    }

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
