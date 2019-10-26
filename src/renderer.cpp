#include "renderer.hpp"

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
}

const RGBImage &Renderer::GetRenderedImage() const
{
    return m_renderedScene;
}
