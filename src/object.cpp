#include "object.hpp"

Object::Object(/* args */)
{
}

Object::~Object()
{
}

Object::Object(const Vector3 &t_origin) : m_origin(t_origin)
{
}

Vector3 Object::GetOrigin() const
{
    return m_origin;
}

int Object::GetIntersectionWithRay(const Vector3 &ray,
                           const Vector3 &rayOrigin,
                           std::array<Vector3, 2> &intersectionPoints) const
{
    return -1;
}