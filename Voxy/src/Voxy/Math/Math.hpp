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
        _data = glm::mat4_cast(rotation);
        _data = glm::scale(_data, scale);
        _data = glm::translate(_data, position);
    }

    operator glm::mat4 &() { return _data; }
    operator const glm::mat4 &() const { return _data; }
    Matrix4 &operator=(const glm::mat4 &mat) {
        _data = mat;
        return *this;
    }

private:
    glm::mat4 _data;
};

} // namespace Voxy::Math
