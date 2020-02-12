#ifndef _RENDERER_HPP_
#define _RENDERER_HPP_
#include "scene.hpp"
#include "camera.hpp"
#include <png++/png.hpp>

class Renderer
{
private:
    Scene m_sceneToRender;
    png::image<png::rgba_pixel> m_renderedScene;
    Camera m_camera;
    std::vector<double> m_distanceBuffer;
    double m_aspectRatio;
    double m_maxRes{100};

public:
    Renderer() = default;
    ~Renderer() = default;
    void SetScene(const Scene &t_scene);
    void SetCamera(const Camera &t_camera);
    void WriteRenderedImage(const char* t_fileName);
    void Render();

    void SetAspectRatio(double t_aspectRatio);
    void SetResolution(double t_res);

    double GetAspectRatio() const;
    double GetResolution() const;

    void GetImageResolution(std::array<unsigned int, 2> &t_imageRes);
};

#endif //_RENDERER_HPP_