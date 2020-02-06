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

void Renderer::Render()
{
    double xRes = 0, yRes = 0;
    this->m_camera.GetResolution(xRes, yRes);
    m_renderedScene.resize(xRes * yRes);

    double maxRes = static_cast<double>(std::max(xRes, yRes));
    double imagePlaneWidth = xRes / maxRes;
    double imagePlaneHeight = yRes / maxRes;

    Vector3 imagePlaneCenter = m_camera.GetOrigin() +
                               m_camera.GetViewDirection() * m_focalLength;

    Vector3 imagePlaneTopLeft = imagePlaneCenter +
                                m_camera.GetLeftDirection() * imagePlaneWidth * 0.5 +
                                m_camera.GetUpDirection() * imagePlaneHeight * 0.5;

    Vector3 imagePlaneRightDir = m_camera.GetLeftDirection() * -1.0;
    Vector3 imagePlaneDownDir = m_camera.GetUpDirection() * -1.0;

    double pixelWidth = imagePlaneWidth / xRes;
    double pixelHeight = imagePlaneHeight / yRes;

    for (unsigned int i = 0; i < xRes; i++)
    {
        for (unsigned int j = 0; j < yRes; j++)
        {
            Vector3 rayOrigin, rayDirection;
            Vector3 rightOffset = imagePlaneRightDir * pixelWidth;
            Vector3 downOffset = imagePlaneDownDir * pixelHeight;
            Vector3 pixelTopLeft = imagePlaneTopLeft + rightOffset * i + downOffset * j;
            rayOrigin = pixelTopLeft + rightOffset * 0.5 +
                        downOffset * 0.5;
            rayDirection = rayOrigin - m_camera.GetOrigin();
            rayDirection.Normalize();
#ifdef DEBUG_RAY
            std::cout << "===================================================================================\n";
            std::cout << "Ray Origin: " << rayOrigin << std::endl;
            std::cout << "Ray Direction: " << rayDirection << std::endl;
            std::cout << "===================================================================================\n";
#endif
            for (auto obj : m_sceneToRender.GetObjectList())
            {
                std::array<Vector3, 2> intersectionPts;
                int nIntPts = obj->GetIntersectionWithRay(rayDirection, rayOrigin, intersectionPts);

                RGBColor pixelColor(0, 0, 0);
                if (nIntPts > 0)
                {
                    pixelColor = obj->GetColor();
                }
                m_renderedScene[i * xRes + j] = m_renderedScene[i * xRes + j] + pixelColor;
#ifdef DEBUG_RENDER
                {
                    std::cout << "===================================================================================\n";
                    std::cout << "Intersection Point 1: " << intersectionPts.at(0) << std::endl;
                    std::cout << "Intersection Point 2: " << intersectionPts.at(1) << std::endl;
                    std::cout << "Pixel Color: " << m_renderedScene[i * xRes + j] << std::endl;
                    std::cout << "===================================================================================\n";
                }
#endif
            }
        }
    }
}

const RGBImage &Renderer::GetRenderedImage() const
{
    return m_renderedScene;
}
