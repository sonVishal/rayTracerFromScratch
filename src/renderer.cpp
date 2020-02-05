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
    m_renderedScene.reserve(xRes * yRes);

    double imagePlaneHeight = m_imagePlaneWidth * yRes / xRes;

    Vector3 imagePlaneCenter = m_camera.GetOrigin() +
                               m_camera.GetViewDirection() * m_imagePlaneDistance;

    Vector3 imagePlaneTopLeft = imagePlaneCenter +
                                m_camera.GetLeftDirection() * m_imagePlaneWidth * 0.5 +
                                m_camera.GetUpDirection() * imagePlaneHeight * 0.5;

    Vector3 imagePlaneRightDir = m_camera.GetLeftDirection() * -1.0;
    Vector3 imagePlaneDownDir = m_camera.GetUpDirection() * -1.0;

    for (auto obj : m_sceneToRender.GetObjectList())
    {
        std::cout << "===================================================================================\n";
        for (unsigned int i = 0; i < xRes; i++)
        {
            for (unsigned int j = 0; j < yRes; j++)
            {
                std::cout << "----------------------------------------\n";
                Vector3 rayOrigin, rayDirection;
                Vector3 pixelTopLeft = imagePlaneTopLeft + imagePlaneRightDir * i + imagePlaneDownDir * j;
                rayOrigin = pixelTopLeft + imagePlaneRightDir * 0.5 * m_imagePlaneDistance +
                            imagePlaneDownDir * 0.5 * m_imagePlaneDistance;
                rayDirection = rayOrigin - m_camera.GetOrigin();
                rayDirection.Normalize();

                std::array<Vector3, 2> intersectionPts;
                int nIntPts = obj->GetIntersectionWithRay(rayDirection, rayOrigin, intersectionPts);

                RGBColor pixelColor(0, 0, 0);
                switch (nIntPts)
                {
                case 0:
                    pixelColor = RGBColor(255, 0, 0);
                    break;
                case 1:
                    pixelColor = RGBColor(0, 255, 0);
                    break;
                case 2:
                    pixelColor = RGBColor(0, 0, 255);
                    break;
                default:
                    break;
                }
                m_renderedScene.emplace_back(pixelColor);
                {
                    std::cout << "Ray Origin: " << rayOrigin << '\n';
                    std::cout << "Ray Direction: " << rayDirection << '\n';
                    std::cout << "Intersection Point 1: " << intersectionPts.at(0) << '\n';
                    std::cout << "Intersection Point 2: " << intersectionPts.at(1) << '\n';
                    std::cout << "Pixel Color: " << pixelColor;
                }
            }
        }
        std::cout << "===================================================================================\n";
    }
}

const RGBImage &Renderer::GetRenderedImage() const
{
    return m_renderedScene;
}
