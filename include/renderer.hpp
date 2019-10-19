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

public:
    Renderer();
    ~Renderer();
    void SetScene(const Scene &t_scene);
    const RGBImage& GetRenderedImage() const;
    void Render();
};

#endif //_RENDERER_HPP_