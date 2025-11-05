#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace Voxy::Math {

typedef glm::vec2 Vector2;
typedef glm::vec3 Vector3;
typedef glm::vec4 Vector4;

typedef glm::quat Quaternion;

struct Matrix4 {
    Matrix4() = default;
    Matrix4(Vector3 position, Quaternion rotation, Vector3 scale) {
        m_Data = glm::mat4_cast(rotation);
        m_Data = glm::scale(m_Data, scale);
        m_Data = glm::translate(m_Data, position);
    }

    operator glm::mat4 &() { return m_Data; }
    operator const glm::mat4 &() const { return m_Data; }
    Matrix4 &operator=(const glm::mat4 &mat) {
        m_Data = mat;
        return *this;
    }

private:
    glm::mat4 m_Data;
};

} // namespace Voxy::Math
