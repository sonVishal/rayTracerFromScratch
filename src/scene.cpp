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

void Scene::AddObjects(int t_nObjects, Object *t_objects)
{
    for (int i = 0; i < t_nObjects; i++)
    {
        m_objects.push_back(t_objects + i);
    }
}

void Scene::SetAmbientColor(const png::rgba_pixel &t_color)
{
    m_ambientColor = t_color;
}

const png::rgba_pixel Scene::GetAmbientColor() const
{
    return m_ambientColor;
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