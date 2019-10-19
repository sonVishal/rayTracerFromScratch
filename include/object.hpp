#ifndef _OBJECT_HPP_
#define _OBJECT_HPP_
#include "vector.hpp"

class Object
{
private:
    Vector3 m_origin{0.0};

public:
    Object();
    Object(const Vector3 &t_origin);
    ~Object();
};

#endif //_OBJECT_HPP_