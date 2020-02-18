#ifndef _SCENE_HPP_
#define _SCENE_HPP_
#include <vector>
#include "sphere.hpp"
#include "light.hpp"
#include "camera.hpp"
#include <png++/rgba_pixel.hpp>

class Scene
{
private:
    std::vector<Object *> m_objects;
    std::vector<Light *> m_lights;
    png::rgba_pixel m_ambientColor;
    Camera m_camera;

public:
    Scene();
    void AddLight(Light *t_light);
    void AddObject(Object *t_object);
    void AddObjects(int t_nObjects, Object *t_objects);
    void SetAmbientColor(const png::rgba_pixel &t_color);
    const png::rgba_pixel GetAmbientColor() const;
    void SetCamera(const Camera &t_camera);
    unsigned int GetNumberOfObjects() const;
    unsigned int GetNumberOfLights() const;
    const Object &GetObjectAt(unsigned int) const;
    const Light &GetLightAt(unsigned int) const;
    const std::vector<Object *> &GetObjectList() const;
    const std::vector<Light *> &GetLightList() const;
    ~Scene();
};

#endif //_SCENE_HPP_