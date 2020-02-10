#include "renderer.hpp"
#include "scene.hpp"

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

void Renderer::GetImageResolution(std::array<unsigned int, 2> &t_imageRes)
{
    t_imageRes.at(0) = m_maxRes;
    t_imageRes.at(1) = m_aspectRatio * t_imageRes.at(0);
}

void Renderer::Render()
{
    double imagePlaneWidth = m_camera.GetImageWidth();
    double imagePlaneHeight = m_aspectRatio * imagePlaneWidth;

    Vector3 imagePlaneCenter = m_camera.GetImagePlaneCenter();
    Vector3 imagePlaneTopLeft = imagePlaneCenter +
                                m_camera.GetLeftDirection() * imagePlaneWidth * 0.5 +
                                m_camera.GetUpDirection() * imagePlaneHeight * 0.5;

    Vector3 imagePlaneRightDir = m_camera.GetLeftDirection() * -1.0;
    Vector3 imagePlaneDownDir = m_camera.GetUpDirection() * -1.0;

    std::array<unsigned int, 2> resolution;
    GetImageResolution(resolution);

    double pixelWidth = imagePlaneWidth / resolution.at(0);
    double pixelHeight = imagePlaneHeight / resolution.at(1);

    double pixelXoffset = 0.5, pixelYoffset = 0.5;

    for (unsigned int i = 0; i < resolution.at(0); i++)
    {
        for (unsigned int j = 0; j < resolution.at(1); j++)
        {
            Vector3 rayOrigin, rayDirection;
            Vector3 rightOffset = imagePlaneRightDir * pixelWidth;
            Vector3 downOffset = imagePlaneDownDir * pixelHeight;

            Vector3 pixelTopLeft = imagePlaneTopLeft + rightOffset * i + downOffset * j;
            rayOrigin = pixelTopLeft + rightOffset * pixelXoffset +
                        downOffset * pixelYoffset;
            rayDirection = rayOrigin - m_camera.GetOrigin();
            rayDirection.Normalize();

            int nIntPts = 0;
            std::array<Vector3, 2> intersectionPts;
            for (auto obj : m_sceneToRender.GetObjectList())
            {
                nIntPts = obj->GetIntersectionWithRay(rayDirection, rayOrigin, intersectionPts);

                RGBColor pixelColor(0, 0, 0);
                if (nIntPts > 0)
                {
                    pixelColor = obj->GetColor();
                }
                m_renderedScene.emplace_back(pixelColor);
            }
            std::cout << rayOrigin << std::endl;
        }
    }
}

const RGBImage &Renderer::GetRenderedImage() const
{
    return m_renderedScene;
}
