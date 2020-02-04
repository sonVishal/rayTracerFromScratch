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
    unsigned int xRes = 0, yRes = 0;
    m_camera.GetResolution(xRes, yRes);
    m_renderedScene.reserve(xRes * yRes);

    double maxRes = static_cast<double>(std::max(xRes, yRes));
    double xLen = xRes / maxRes, xLenBy2 = xLen / 2.0;
    double yLen = yRes / maxRes, yLenBy2 = yLen / 2.0;
    auto imagePlaneTopLeft = m_camera.GetOrigin() +
                             m_camera.GetViewDirection() +
                             (m_camera.GetLeftDirection() * xLenBy2) +
                             (m_camera.GetUpDirection() * yLenBy2);

    for (unsigned int i = 0; i < xRes; i++)
    {
        for (unsigned int j = 0; j < yRes; j++)
        {
            auto rayOrigin = imagePlaneTopLeft +
                                m_camera.GetLeftDirection() * (-0.5 * (i + 1)) +
                                m_camera.GetUpDirection() * (-0.5 * (j + 1));
            auto rayDirection = rayOrigin -
                                m_camera.GetOrigin();
            rayDirection.Normalize();
            auto objectList = m_sceneToRender.GetObjectList();
            RGBColor thisRayColor(0, 0, 0);
            for (auto obj : objectList)
            {
                std::array<Vector3, 2> intsctPts;
                if (obj.GetIntersectionWithRay(rayDirection, rayOrigin, intsctPts))
                {
                    m_renderedScene.emplace_back(RGBColor(0,0,0));
                }
                else
                {
                    m_renderedScene.emplace_back(RGBColor(255,255,255));
                }
            }
        }
    }
}

const RGBImage &Renderer::GetRenderedImage() const
{
    return m_renderedScene;
}
