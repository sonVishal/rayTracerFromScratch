#include "object.hpp"

Object::Object(/* args */) : m_diffuseColor()
{
}

Object::~Object()
{
}

Object::Object(const Vector3 &t_origin) : m_origin(t_origin), m_diffuseColor()
{
}

Object::Object(const png::rgba_pixel &t_color) : m_diffuseColor(t_color)
{
}

Object::Object(const Vector3 &t_origin,
               const png::rgba_pixel &t_color) : m_origin(t_origin),
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

void Object::SetColor(const png::rgba_pixel &t_color)
{
    m_diffuseColor = t_color;
}

const png::rgba_pixel Object::GetColor() const
{
    return m_diffuseColor;
}