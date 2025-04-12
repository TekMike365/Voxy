#include "Scene.h"

#include "Components/Camera.h"

#include "Voxy/Renderer/Renderer.h"

namespace Voxy
{
    Scene::Scene()
    {
        m_Registry = std::make_shared<entt::registry>();
    }

    void Scene::Update(TimeStep dt)
    {
        // TODO: ! make it data oriented !

        bool began = false;
        for (auto [ett, camera] : m_Registry->view<Camera>().each())
        {
            if (!camera.IsMain())
                continue;
            // Camera is Main
            Entity entity(ett, m_Registry);
            Transform defaultTransform;
            Renderer::Begin(&camera, &(entity.HasComponent<Transform>() ? entity.GetComponent<Transform>() : defaultTransform));
            began = true;
        }

        if (began)
            Renderer::End();
    }
}