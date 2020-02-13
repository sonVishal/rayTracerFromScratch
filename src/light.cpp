#include "light.hpp"

Light::Light()
{
}

Light::~Light()
{
}

Light::Light(const Vector3 &t_origin) : m_origin(t_origin)
{
}

Light::Light(const Vector3 &t_origin, unsigned int t_intensity) : m_origin{t_origin}, m_intensity{t_intensity}
{
}

void Light::SetIntensity(unsigned int t_intensity)
{
    m_intensity = t_intensity;
}

unsigned int Light::GetIntensity() const
{
    return m_intensity;
}

void Light::SetColor(const png::rgb_pixel &t_color)
{
    m_color = t_color;
}

png::rgb_pixel Light::GetColor() const
{
    return m_color;
}