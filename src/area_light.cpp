#include "area_light.hpp"

AreaLight::AreaLight()
{
}

AreaLight::AreaLight(const Vector3 &t_origin, const Vector3 &t_normal, double t_intensity) : Light(t_origin, t_intensity), m_normal{t_normal}
{
}

Vector3 AreaLight::GetNormal() const
{
    return m_normal;
}

void AreaLight::SetNormal(const Vector3 &t_normal)
{
    m_normal = t_normal;
}

double AreaLight::GetIntensityAt(const Vector3& t_point) const
{
    // TODO!!!!
    return m_intensity;
}

AreaLight::~AreaLight()
{
}