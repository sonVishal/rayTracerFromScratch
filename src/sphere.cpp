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

Sphere::Sphere(const Vector3 &t_origin) : Object(t_origin)
{
}