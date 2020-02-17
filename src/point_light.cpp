#include "point_light.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

PointLight::PointLight()
{
}

PointLight::~PointLight()
{
}

PointLight::PointLight(const Vector3 &t_origin) : Light(t_origin)
{
}

PointLight::PointLight(const Vector3 &t_origin, double t_intensity) : Light(t_origin, t_intensity)
{
}

double PointLight::GetIntensityAt(const Vector3& t_point) const
{
    double distance = (t_point - m_origin).GetMagnitude();
    return m_intensity * 0.25 / (distance * distance * M_PI); // inverse square law
}
