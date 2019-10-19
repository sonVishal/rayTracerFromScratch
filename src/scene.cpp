#include "scene.hpp"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::AddLight(const Light &t_light)
{
    m_lights.emplace_back(t_light);
}

void Scene::AddObject(const Object &t_object)
{
    m_objects.emplace_back(t_object);
}

void Scene::SetAmbientColor(const RGBColor &t_color)
{
    m_ambientColor = t_color;
}

void Scene::SetCamera(const Camera& t_camera)
{
    m_camera = t_camera;
}