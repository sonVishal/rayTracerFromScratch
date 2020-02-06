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

Object::Object(const RGBColor &t_color) : m_diffuseColor(t_color)
{
}

Object::Object(const Vector3 &t_origin,
               const RGBColor &t_color) : m_origin(t_origin),
                                          m_diffuseColor(t_color)
{
}

Vector3 Object::GetOrigin() const
{
    return m_origin;
}

void Object::SetOrigin(const Vector3& t_origin)
{
    m_origin = t_origin;
}

int Object::GetIntersectionWithRay(const Vector3 &ray,
                                   const Vector3 &rayOrigin,
                                   std::array<Vector3, 2> &intersectionPoints) const
{
    return -1;
}

void Object::SetColor(const RGBColor &t_color)
{
    m_diffuseColor = t_color;
}

const RGBColor Object::GetColor() const
{
    return m_diffuseColor;
}