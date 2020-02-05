#ifndef _OBJECT_HPP_
#define _OBJECT_HPP_
#include "vector3.hpp"
#include "rgbcolor.hpp"

class Object
{
protected:
    Vector3 m_origin{0.0};
    RGBColor m_diffuseColor{0};

public:
    Object();
    Object(const Vector3 &t_origin);
    Object(const RGBColor &t_color);
    Object(const Vector3 &t_origin,
           const RGBColor &t_color);
    Vector3 GetOrigin() const;
    void SetColor(const RGBColor &t_color);
    const RGBColor GetColor() const;
    virtual int GetIntersectionWithRay(const Vector3 &ray,
                                       const Vector3 &rayOrigin,
                                       std::array<Vector3, 2> &intersectionPoints) const;
    virtual ~Object();
};

#endif //_OBJECT_HPP_