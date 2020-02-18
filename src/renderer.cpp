#include "renderer.hpp"
#include "scene.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <limits>

void Renderer::SetScene(const Scene &t_scene)
{
    m_sceneToRender = t_scene;
}

void Renderer::SetCamera(const Camera &t_camera)
{
    m_camera = t_camera;
}

void Renderer::SetAspectRatio(double t_aspectRatio)
{
    m_aspectRatio = t_aspectRatio;
}

void Renderer::SetResolution(double t_res)
{
    m_maxRes = t_res;
}

double Renderer::GetAspectRatio() const
{
    return m_aspectRatio;
}

double Renderer::GetResolution() const
{
    return m_maxRes;
}

void Renderer::GetImageResolution(std::array<unsigned int, 2> &t_imageRes) const
{
    t_imageRes.at(1) = m_maxRes;
    t_imageRes.at(0) = m_aspectRatio * t_imageRes.at(1);
}

unsigned int Renderer::GetSamplesPerPixel() const
{
    return m_raysPerPixel;
}

void Renderer::SetSamplesPerPixel(unsigned int t_numSamples)
{
    m_raysPerPixel = t_numSamples;
}

void Renderer::GetImagePlaneInfo(Vector3 &t_imagePlaneTopLeft,
                                 Vector3 &t_imagePlaneRightDir,
                                 Vector3 &t_imagePlaneDownDir,
                                 unsigned int &t_xPixels,
                                 unsigned int &t_yPixels,
                                 double &t_pixelWidth,
                                 double &t_pixelHeight) const
{
    std::array<unsigned int, 2> resolution;
    this->GetImageResolution(resolution);

    double revisedAspectRatio = static_cast<double>(resolution.at(0)) / static_cast<double>(resolution.at(1));

    double imagePlaneHeight = m_camera.GetImageHeight();
    double imagePlaneWidth = revisedAspectRatio * imagePlaneHeight;

    Vector3 imagePlaneCenter = m_camera.GetImagePlaneCenter();
    t_imagePlaneTopLeft = imagePlaneCenter +
                          m_camera.GetLeftDirection() * imagePlaneWidth * 0.5 +
                          m_camera.GetUpDirection() * imagePlaneHeight * 0.5;

    t_imagePlaneRightDir = m_camera.GetLeftDirection() * -1.0;
    t_imagePlaneDownDir = m_camera.GetUpDirection() * -1.0;

    t_xPixels = resolution.at(0);
    t_yPixels = resolution.at(1);

    t_pixelWidth = imagePlaneWidth / resolution.at(0);
    t_pixelHeight = imagePlaneHeight / resolution.at(1);
}

void Renderer::GetRayInfo(Vector3 &t_rayOrigin, Vector3 &t_rayDirection,
                          const Vector3 &t_imagePlaneTopLeft,
                          const Vector3 &t_imagePlaneRightDir,
                          const Vector3 &t_imagePlaneDownDir,
                          double t_pixelSize, double t_rightOffset,
                          double t_downOffset,
                          unsigned int t_xIdx, unsigned int t_yIdx) const
{
    Vector3 rightOffsetDir = t_imagePlaneRightDir * t_pixelSize;
    Vector3 downOffsetDir = t_imagePlaneDownDir * t_pixelSize;

    Vector3 pixelTopLeft = t_imagePlaneTopLeft + rightOffsetDir * t_xIdx + downOffsetDir * t_yIdx;
    t_rayOrigin = pixelTopLeft + rightOffsetDir * t_rightOffset +
                  downOffsetDir * t_downOffset;
    t_rayDirection = t_rayOrigin - m_camera.GetOrigin();
    t_rayDirection.Normalize();
}

static png::rgba_pixel computeLambertPixelColor(const Light &t_light, const Object &t_obj,
                                                const Vector3 &t_intPoint,
                                                const Vector3 &t_normal)
{
    Vector3 lightDir = (t_light.GetOrigin() - t_intPoint).GetNormalized();
    double lightIntensity = (t_obj.GetAlbedo() / M_PI * t_light.GetIntensity());
    double lambertTerm = std::max(0.0, t_normal % lightDir);
    png::rgba_pixel outputValue(0, 0, 0, 255); // TODO: alpha!
    outputValue.red = std::min(255, int(t_obj.GetColor().red + lightIntensity * lambertTerm * t_light.GetColor().red));
    outputValue.green = std::min(255, int(t_obj.GetColor().green + lightIntensity * lambertTerm * t_light.GetColor().green));
    outputValue.blue = std::min(255, int(t_obj.GetColor().blue + lightIntensity * lambertTerm * t_light.GetColor().blue));

    return outputValue;
}

void Renderer::TraceRay(const Vector3 &t_rayDir, const Vector3 &t_rayOrigin,
                        const std::vector<Object *> t_objList,
                        png::rgba_pixel &t_pixelColor) const
{
    // for (size_t i = 0; i < m_maxBounces; i++)
    // {
    Vector3 intPoint, surfNormal;
    Object *intersectedObj = nullptr;
    double minDist = std::numeric_limits<double>::max();
    for (auto obj : t_objList)
    {
        Vector3 intersectPoint, normal;
        double distSq = 0.0;
        if (obj->GetClosestIntersectionWithRay(t_rayDir, t_rayOrigin, intersectPoint, normal))
        {
            distSq = (intersectPoint - obj->GetOrigin()).GetMagnitudeSq();
            if (distSq < minDist)
            {
                intPoint = intersectPoint;
                surfNormal = normal;
                intersectedObj = obj;
                minDist = distSq;
            }
        }
    }

    if (intersectedObj)
    {
        t_pixelColor = computeLambertPixelColor(m_sceneToRender.GetLightAt(0),
                                                *intersectedObj, intPoint,
                                                surfNormal);
    }
    else
    {
        t_pixelColor = m_sceneToRender.GetAmbientColor();
    }
}

void Renderer::Render()
{
    Vector3 imagePlaneTopLeft, imagePlaneRightDir, imagePlaneDownDir;
    double pixelWidth = 0.0, pixelHeight = 0.0;
    unsigned int xPixels = 0, yPixels = 0;

    GetImagePlaneInfo(imagePlaneTopLeft, imagePlaneRightDir, imagePlaneDownDir,
                      xPixels, yPixels, pixelWidth, pixelHeight);

    m_renderedScene.resize(xPixels, yPixels);

    double pixelXoffset = 0.5, pixelYoffset = 0.5;

    for (unsigned int y = 0; y < yPixels; y++)
    {
        for (unsigned int x = 0; x < xPixels; x++)
        {
            Vector3 rayOrigin, rayDirection;

            GetRayInfo(rayOrigin, rayDirection, imagePlaneTopLeft,
                       imagePlaneRightDir, imagePlaneDownDir, pixelWidth,
                       pixelXoffset, pixelYoffset, x, y);

            TraceRay(rayDirection, rayOrigin,
                     m_sceneToRender.GetObjectList(),
                     m_renderedScene[y][x]);
        }
    }
}

void Renderer::WriteRenderedImage(const char *t_fileName)
{
    m_renderedScene.write(t_fileName);
}

void Renderer::SetMaxBounces(unsigned int t_maxBounces)
{
    m_maxBounces = t_maxBounces;
}

unsigned int Renderer::GetMaxBounces() const
{
    return m_maxBounces;
}