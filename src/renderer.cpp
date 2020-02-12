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
    t_imageRes.at(1) = m_maxRes;
    t_imageRes.at(0) = m_aspectRatio * t_imageRes.at(1);
}

void Renderer::Render()
{
    std::array<unsigned int, 2> resolution;
    GetImageResolution(resolution);

    double revisedAspectRatio = static_cast<double>(resolution.at(0)) / static_cast<double>(resolution.at(1));

    double imagePlaneHeight = m_camera.GetImageHeight();
    double imagePlaneWidth = revisedAspectRatio * imagePlaneHeight;

    Vector3 imagePlaneCenter = m_camera.GetImagePlaneCenter();
    Vector3 imagePlaneTopLeft = imagePlaneCenter +
                                m_camera.GetLeftDirection() * imagePlaneWidth * 0.5 +
                                m_camera.GetUpDirection() * imagePlaneHeight * 0.5;

    Vector3 imagePlaneRightDir = m_camera.GetLeftDirection() * -1.0;
    Vector3 imagePlaneDownDir = m_camera.GetUpDirection() * -1.0;

    double pixelWidth = imagePlaneWidth / resolution.at(0);
    double pixelHeight = imagePlaneHeight / resolution.at(1);

    double pixelXoffset = 0.5, pixelYoffset = 0.5;

    m_renderedScene.resize(resolution.at(0), resolution.at(1));

    for (unsigned int y = 0; y < resolution.at(1); y++)
    {
        for (unsigned int x = 0; x < resolution.at(0); x++)
        {
            Vector3 rayOrigin, rayDirection;
            Vector3 rightOffset = imagePlaneRightDir * pixelWidth;
            Vector3 downOffset = imagePlaneDownDir * pixelHeight;

            Vector3 pixelTopLeft = imagePlaneTopLeft + rightOffset * x + downOffset * y;
            rayOrigin = pixelTopLeft + rightOffset * pixelXoffset +
                        downOffset * pixelYoffset;
            rayDirection = rayOrigin - m_camera.GetOrigin();
            rayDirection.Normalize();

            int nIntPts = 0;
            png::rgba_pixel pixelColor(m_sceneToRender.GetAmbientColor());
            for (auto obj : m_sceneToRender.GetObjectList())
            {
                std::array<Vector3, 2> intersectionPts;
                nIntPts = obj->GetIntersectionWithRay(rayDirection, rayOrigin, intersectionPts);

                if (nIntPts > 0)
                {
                    pixelColor = obj->GetColor();
                }
            }
            m_renderedScene[y][x] = pixelColor;
        }
    }
}

void Renderer::WriteRenderedImage(const char *t_fileName)
{
    m_renderedScene.write(t_fileName);
}
