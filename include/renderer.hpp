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
    unsigned int m_maxBounces{5};
    unsigned int m_raysPerPixel{1};

    void TraceRay(const Vector3 &t_rayDir, const Vector3 &t_rayOrigin,
                  const std::vector<Object *> t_objList, png::rgba_pixel &t_pixelColor) const;

    void GetImagePlaneInfo(Vector3 &t_imagePlaneTopLeft,
                           Vector3 &t_imagePlaneRightDir,
                           Vector3 &t_imagePlaneDownDir,
                           unsigned int &t_xPixels,
                           unsigned int &t_yPixels,
                           double &t_pixelWidth,
                           double &t_pixelHeight) const;

    void GetRayInfo(Vector3 &t_rayOrigin, Vector3 &t_rayDirection,
                    const Vector3 &t_imagePlaneTopLeft,
                    const Vector3 &t_imagePlaneRightDir,
                    const Vector3 &t_imagePlaneDownDir,
                    double t_pixelSize, double t_rightOffset,
                    double t_downOffset,
                    unsigned int t_xIdx, unsigned int t_yIdx) const;

public:
    Renderer() = default;
    ~Renderer() = default;
    void SetScene(const Scene &t_scene);
    void SetCamera(const Camera &t_camera);
    void WriteRenderedImage(const char *t_fileName);
    void Render();

    void SetAspectRatio(double t_aspectRatio);
    void SetResolution(double t_res);
    void SetMaxBounces(unsigned int t_maxBounces);
    void SetSamplesPerPixel(unsigned int t_numSamples);

    double GetAspectRatio() const;
    double GetResolution() const;
    unsigned int GetMaxBounces() const;
    unsigned int GetSamplesPerPixel() const;

    void GetImageResolution(std::array<unsigned int, 2> &t_imageRes) const;
};

#endif //_RENDERER_HPP_