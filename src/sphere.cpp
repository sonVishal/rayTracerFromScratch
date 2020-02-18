#include "sphere.hpp"
#include "quadratic.hpp"
#include "object.hpp"

Sphere::Sphere()
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

int Sphere::GetIntersectionWithRayInternal(const Vector3 &t_ray,
                                           const Vector3 &t_rayOrigin,
                                           std::pair<Vector3, Vector3> &t_intersectionPoints) const
{
    int nIntersectionPts = 0;

    double a = 0.0, b = 0.0, c = 0.0;
    QuadraticEq intersectionEq;

    a = t_ray.GetMagnitudeSq();
    b = (t_ray * 2.0) % (t_rayOrigin - m_origin);
    c = t_rayOrigin.GetMagnitudeSq() + m_origin.GetMagnitudeSq() - 2.0 * (t_rayOrigin % m_origin) - m_radius * m_radius;

    intersectionEq.SetEquation(a, b, c);
    nIntersectionPts = intersectionEq.CalculateRoots();
    auto roots = intersectionEq.GetRoots();

    switch (nIntersectionPts)
    {
    case 1:
        t_intersectionPoints.first = t_rayOrigin + t_ray * roots.at(0);
        break;
    case 2:
        t_intersectionPoints.first = t_rayOrigin + t_ray * roots.at(0);
        t_intersectionPoints.second = t_rayOrigin + t_ray * roots.at(1);
        break;
    default:
        break;
    }

    return nIntersectionPts;
}

void Sphere::GetIntersectionWithRay(const Vector3 &t_ray,
                                    const Vector3 &t_rayOrigin,
                                    std::vector<Vector3> &t_intersectionPoints) const
{
    std::pair<Vector3, Vector3> intPts;
    int nIntersectionPts = GetIntersectionWithRayInternal(t_ray, t_rayOrigin, intPts);

    t_intersectionPoints.clear();
    switch (nIntersectionPts)
    {
    case 1:
        t_intersectionPoints.emplace_back(intPts.first);
        break;
    case 2:
        t_intersectionPoints.emplace_back(intPts.first);
        t_intersectionPoints.emplace_back(intPts.second);
        break;
    default:
        break;
    }
}

bool Sphere::GetClosestIntersectionWithRay(const Vector3 &t_ray,
                                           const Vector3 &t_rayOrigin,
                                           Vector3 &t_intPoint,
                                           Vector3 &t_normal) const
{
    std::pair<Vector3, Vector3> intPts;
    int nIntersectionPts = GetIntersectionWithRayInternal(t_ray, t_rayOrigin, intPts);

    double dist1 = 0.0, dist2 = 0.0;
    switch (nIntersectionPts)
    {
    case 1:
        t_intPoint = intPts.first;
        t_normal = t_intPoint - m_origin;
        t_normal.Normalize();
        break;
    case 2:
        dist1 = (intPts.first - m_origin).GetMagnitude();
        dist2 = (intPts.second - m_origin).GetMagnitude();
        t_intPoint = (dist1 < dist2) ? intPts.first : intPts.second;
        t_normal = t_intPoint - m_origin;
        t_normal.Normalize();
        break;
    default:
        break;
    }

    return (nIntersectionPts != 0);
}