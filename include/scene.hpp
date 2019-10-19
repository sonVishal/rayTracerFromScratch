#ifndef _SCENE_HPP_
#define _SCENE_HPP_
#include <vector>
#include "sphere.hpp"
#include "light.hpp"
#include "rgbcolor.hpp"
#include "camera.hpp"

class Scene
{
private:
    std::vector<Object> m_objects;
    std::vector<Light> m_lights;
    RGBColor m_ambientColor{0};
    Camera m_camera;

public:
    Scene();
    void AddLight(const Light &t_light);
    void AddObject(const Object &t_object);
    void SetAmbientColor(const RGBColor &t_color);
    void SetCamera(const Camera &t_camera);

    ~Scene();
};

#endif //_SCENE_HPP_