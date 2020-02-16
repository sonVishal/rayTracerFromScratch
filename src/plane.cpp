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

void Plane::GetIntersectionWithRay(const Vector3 &ray,
                                  const Vector3 &rayOrigin,
                                  std::vector<Vector3> &intersectionPoints) const
{
    double param = (m_normal % (m_origin - rayOrigin)) / (ray % m_normal);
    if (param > 0.0)
    {
        Vector3 intersectionPoint = rayOrigin + ray * param;
        double planeX = std::fabs(intersectionPoint % m_xAxis);
        double planeY = std::fabs(intersectionPoint % m_yAxis);
        if (planeX <= m_lengthBy2 && planeY <= m_breadthBy2)
        {
            intersectionPoints.emplace_back(intersectionPoint);
        }
    }
}