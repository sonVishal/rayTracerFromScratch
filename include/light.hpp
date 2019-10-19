#ifndef _LIGHT_HPP_
#define _LIGHT_HPP_
#include "vector3.hpp"

class Light
{
private:
    Vector3 m_origin{0.0};

public:
    Light();
    Light(const Vector3 &t_origin);
    ~Light();
};

#endif //_LIGHT_HPP_