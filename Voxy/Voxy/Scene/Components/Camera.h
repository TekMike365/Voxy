#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Voxy
{
    class Camera
    {
    public:
        Camera(float fovDeg = 120.0f, float aspect = 16.0f / 9.0f, float zNear = 0.1f, float zFar = 100.0f)
            : m_FovDeg(fovDeg), m_Aspect(aspect), m_ZNear(zNear), m_ZFar(zFar) { UpdateProjection(); }
        ~Camera() 
        {
            if (s_MainCamera == this)
                s_MainCamera = nullptr;
        }

        inline const glm::mat4 &GetProjection() const { return m_Projection; }

        inline bool IsMain() const { return s_MainCamera == this; }
        inline void SetAsMain() const { s_MainCamera = this; }

        inline float GetFovDeg() const { return m_FovDeg; }
        inline float GetAspect() const { return m_Aspect; }
        inline float GetZNear() const { return m_ZNear; }
        inline float GetZFar() const { return m_ZFar; }

        inline void SetFOV(float fov)
        {
            m_FovDeg = fov;
            UpdateProjection();
        }
        inline void SetAspect(float aspect)
        {
            m_Aspect = aspect;
            UpdateProjection();
        }
        inline void SetZNear(float zNear)
        {
            m_ZNear = zNear;
            UpdateProjection();
        }
        inline void SetZFar(float zFar)
        {
            m_ZFar = zFar;
            UpdateProjection();
        }

    private:
        inline void UpdateProjection() { m_Projection = glm::perspective(glm::radians(m_FovDeg), m_Aspect, m_ZNear, m_ZFar); }

    private:
        glm::mat4 m_Projection;
        float m_FovDeg;
        float m_Aspect;
        float m_ZNear;
        float m_ZFar;

        static const Camera *s_MainCamera;
    };
};
