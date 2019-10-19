#include "renderer.hpp"

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::SetScene(const Scene& t_scene)
{
    m_sceneToRender = t_scene;
}

void Renderer::Render()
{
}

const RGBImage& Renderer::GetRenderedImage() const
{
    return m_renderedScene;
}
