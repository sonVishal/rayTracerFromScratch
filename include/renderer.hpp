#ifndef _RENDERER_HPP_
#define _RENDERER_HPP_
#include "scene.hpp"
#include "camera.hpp"
#include "rgbcolor.hpp"

class Renderer
{
private:
    Scene m_sceneToRender;
    RGBImage m_renderedScene;
    Camera m_camera;

public:
    Renderer() = default;
    ~Renderer() = default;
    void SetScene(const Scene &t_scene);
    void SetCamera(const Camera &t_camera);
    const RGBImage &GetRenderedImage() const;
    void Render();
};

#endif //_RENDERER_HPP_