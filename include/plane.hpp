#ifndef _PLANE_HPP_
#define _PLANE_HPP_
#include "object.hpp"
#include <png++/rgba_pixel.hpp>
#include "vector3.hpp"

class Plane : public Object
{
private:
    Vector3 m_normal{0.0, 0.0, 1.0},
        m_xAxis{1.0, 0.0, 0.0},
        m_yAxis{0.0, 1.0, 0.0};
    double m_length{1.0}, m_breadth{1.0};
    double m_lengthBy2{0.5}, m_breadthBy2{0.5};

public:
    Plane();
    Plane(Vector3 t_origin);
    Plane(const png::rgba_pixel &t_color);
    Plane(const Vector3 &t_origin,
          const png::rgba_pixel &t_color);
    void SetLength(double t_length);
    void SetBreadth(double t_breadth);
    void GetIntersectionWithRay(const Vector3 &ray,
                               const Vector3 &rayOrigin,
                               std::vector<Vector3> &intersectionPoints) const;
    ~Plane();
};

#endif //_PLANE_HPP_