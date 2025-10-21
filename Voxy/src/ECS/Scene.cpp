#include "Scene.hpp"

namespace Voxy {

Entity Scene::CreateEntity() {
    entt::entity e = m_Registry->create();
    return Entity(e, m_Registry);
}

void Scene::DestroyEntity(Entity &e) { e.Destroy(); }

} // namespace Voxy
