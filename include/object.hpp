#ifndef _OBJECT_HPP_
#define _OBJECT_HPP_
#include "vector3.hpp"
#include <vector>

class Object
{
private:
    Vector3 m_origin{0.0};

protected:
    Object();
    Object(const Vector3 &t_origin);
    ~Object();
};

class ObjectFactory
{
private:
    enum class ObjectType{
        Unknown,
        PointLight,
        Sphere
    };
public:
    ObjectFactory();
    Object* CreateObject(const ObjectType& t_object);
    ~ObjectFactory();
};

using ObjectPtrVector = std::vector<Object*>;

#endif //_OBJECT_HPP_