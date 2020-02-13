#include "sphere.hpp"
#include "quadratic.hpp"
#include "object.hpp"

Sphere::Sphere() : Object()
{
}

Sphere::~Sphere()
{
}

Sphere::Sphere(const png::rgba_pixel &t_color) : Object{t_color}
{
}

Sphere::Sphere(const Vector3 &t_origin, double t_radius)
    : Object(t_origin), m_radius(t_radius)
{
}

void Sphere::SetRadius(double t_radius)
{
    m_radius = t_radius;
}

int Sphere::GetIntersectionWithRay(const Vector3 &rayDirection,
                                   const Vector3 &rayOrigin,
                                   std::array<Vector3, 2> &intersectionPoints) const
{
    int nIntersectionPts = 0;

    double a = 0.0, b = 0.0, c = 0.0;
    QuadraticEq intersectionEq;

    a = rayDirection.GetMagnitudeSq();
    b = (rayDirection * 2.0) % (rayOrigin - m_origin);
    c = rayOrigin.GetMagnitudeSq() + m_origin.GetMagnitudeSq() - 2.0 * (rayOrigin % m_origin) - m_radius * m_radius;

    intersectionEq.SetEquation(a, b, c);
    nIntersectionPts = intersectionEq.CalculateRoots();
    auto roots = intersectionEq.GetRoots();
    switch (nIntersectionPts)
    {
    case 0:
        intersectionPoints.at(0) = intersectionPoints.at(1) = Vector3(0.0);
        break;
    case 1:
        intersectionPoints.at(0) = rayOrigin + rayDirection * roots.at(0);
        intersectionPoints.at(1) = Vector3(0.0);
        break;
    case 2:
        intersectionPoints.at(0) = rayOrigin + rayDirection * roots.at(0);
        intersectionPoints.at(1) = rayOrigin + rayDirection * roots.at(1);
        break;
    default:
        break;
    }

    return nIntersectionPts;
}