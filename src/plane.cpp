#include "plane.hpp"
#include <cmath>

Plane::Plane()
{
}

Plane::Plane(Vector3 t_origin) : Object(t_origin)
{
}

Plane::Plane(const png::rgba_pixel &t_color) : Object(t_color)
{
}

Plane::Plane(const Vector3 &t_origin,
             const png::rgba_pixel &t_color) : Object(t_origin, t_color)
{
}

void Plane::SetLength(double t_length)
{
    m_length = t_length;
    m_lengthBy2 = m_length * 0.5;
}

void Plane::SetBreadth(double t_breadth)
{
    m_breadth = t_breadth;
    m_breadthBy2 = t_breadth * 0.5;
}

Plane::~Plane()
{
}

void Plane::GetIntersectionWithRay(const Vector3 &t_ray,
                                   const Vector3 &t_rayOrigin,
                                   std::vector<Vector3> &t_intersectionPoints) const
{
    Vector3 intPt, surfNormal;
    if (GetClosestIntersectionWithRay(t_ray, t_rayOrigin, intPt, surfNormal))
    {
        t_intersectionPoints.push_back(intPt);
    }
}

bool Plane::GetClosestIntersectionWithRay(const Vector3 &t_ray,
                                          const Vector3 &t_rayOrigin,
                                          Vector3 &t_intPoint,
                                          Vector3 &t_normal) const
{
    bool doesIntersect = false;
    double param = (m_normal % (m_origin - t_rayOrigin)) / (t_ray % m_normal);
    if (param > 0.0)
    {
        t_intPoint = t_rayOrigin + t_ray * param;
        Vector3 plOriginToIntPoint = (t_intPoint - m_origin);
        double planeX = std::fabs(plOriginToIntPoint % m_xAxis);
        double planeY = std::fabs(plOriginToIntPoint % m_yAxis);
        if (planeX <= m_lengthBy2 && planeY <= m_breadthBy2)
        {
            doesIntersect = true;
            t_normal = m_normal;
        }
    }
    return doesIntersect;
}