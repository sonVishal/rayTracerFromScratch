#include "sphere.hpp"

Sphere::Sphere()
{
}

Sphere::~Sphere()
{
}

Sphere::Sphere(const RGBColor &t_color) : m_diffuseColor{t_color}
{
}

Sphere::Sphere(const Vector3 &t_origin, double t_radius)
    : Object(t_origin), m_radius(t_radius)
{
}

void Sphere::SetColor(const RGBColor &t_color)
{
    m_diffuseColor = t_color;
}