#ifndef _OBJECT_HPP_
#define _OBJECT_HPP_
#include "vector3.hpp"
#include <png++/rgba_pixel.hpp>
#include <vector>

class Object
{
protected:
    Vector3 m_origin{0.0};
    png::rgba_pixel m_diffuseColor;

public:
    Object();
    Object(const Vector3 &t_origin);
    Object(const png::rgba_pixel &t_color);
    Object(const Vector3 &t_origin,
           const png::rgba_pixel &t_color);
    Vector3 GetOrigin() const;
    void SetOrigin(const Vector3& t_origin);
    void SetColor(const png::rgba_pixel &t_color);
    const png::rgba_pixel GetColor() const;
    virtual void GetIntersectionWithRay(const Vector3 &ray,
                                       const Vector3 &rayOrigin,
                                       std::vector<Vector3> &intersectionPoints) const = 0;
    virtual ~Object();
};

#endif //_OBJECT_HPP_