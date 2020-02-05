#include "scene.hpp"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::AddLight(Light *t_light)
{
    m_lights.emplace_back(t_light);
}

void Scene::AddObject(Object *t_object)
{
    m_objects.emplace_back(t_object);
}

void Scene::SetAmbientColor(const RGBColor &t_color)
{
    m_ambientColor = t_color;
}

void Scene::SetCamera(const Camera &t_camera)
{
    m_camera = t_camera;
}

unsigned int Scene::GetNumberOfObjects() const
{
    return m_objects.size();
}

const Object &Scene::GetObjectAt(unsigned int t_idx) const
{
    return *m_objects.at(t_idx);
}

const std::vector<Object *> &Scene::GetObjectList() const
{
    return m_objects;
}