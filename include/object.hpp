#ifndef _OBJECT_HPP_
#define _OBJECT_HPP_
#include "vector3.hpp"

class Object
{
protected:
    Vector3 m_origin{0.0};

public:
    Object();
    Object(const Vector3 &t_origin);
    Vector3 GetOrigin() const;
    virtual int GetIntersectionWithRay(const Vector3 &ray,
                                       const Vector3 &rayOrigin,
                                       std::array<Vector3, 2> &intersectionPoints) const;
    ~Object();
};

#endif //_OBJECT_HPP_