// This class contains the representation of a discrete sphere.
#ifndef _SPHERE_HPP_
#define _SPHERE_HPP_
#include "vector3.hpp"
#include "rgbcolor.hpp"
#include "object.hpp"

class Sphere : public Object
{
private:
    double m_radius{0.0};

public:
    Sphere();
    Sphere(const RGBColor &t_color);
    Sphere(const Vector3 &t_origin, double t_radius);
    int GetIntersectionWithRay(const Vector3 &ray,
                               const Vector3 &rayOrigin,
                               std::array<Vector3, 2> &intersectionPoints) const;
    ~Sphere();
};

#endif