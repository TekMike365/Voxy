#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace Voxy
{
    struct Transform
    {
        glm::vec3 Position = glm::vec3(0.0f);
        glm::vec3 Scale = glm::vec3(1.0f);
        glm::quat Rotation = glm::angleAxis(0.0f, glm::vec3(1.0f, 0.0f, 0.0f));

        inline glm::mat4 GetMat() const
        {
            return glm::translate(glm::mat4(1.0f), Position) * glm::scale(glm::mat4(1.0f), Scale) * glm::mat4_cast(Rotation);
        }
    };

}