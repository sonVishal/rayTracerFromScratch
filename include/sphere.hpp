// This class contains the representation of a discrete sphere.
#ifndef _SPHERE_HPP_
#define _SPHERE_HPP_
#include "vector3.hpp"
#include "object.hpp"

class Sphere : public Object
{
private:
    double m_radius{0.0};
    int GetIntersectionWithRayInternal(const Vector3 &t_ray,
                                               const Vector3 &t_rayOrigin,
                                               std::pair<Vector3, Vector3> &t_intersectionPoints) const;

public:
    Sphere();
    Sphere(const png::rgba_pixel &t_color);
    Sphere(const Vector3 &t_origin, double t_radius);
    void GetIntersectionWithRay(const Vector3 &t_ray,
                                const Vector3 &t_rayOrigin,
                                std::vector<Vector3> &t_intersectionPoints) const;
    virtual bool GetClosestIntersectionWithRay(const Vector3 &t_ray,
                                               const Vector3 &t_rayOrigin,
                                               Vector3 &t_intPoint,
                                               Vector3 &t_normal) const;
    void SetRadius(double t_radius);
    ~Sphere();
};

#endif