#ifndef _AREA_LIGHT_HPP_
#define _AREA_LIGHT_HPP_
#include "light.hpp"
#include "vector3.hpp"

class AreaLight : public Light
{
private:
    Vector3 m_normal{0.0};

public:
    AreaLight();
    AreaLight(const Vector3 &t_origin, const Vector3 &t_normal, double t_intensity);
    Vector3 GetNormal() const;
    void SetNormal(const Vector3 &t_normal);
    ~AreaLight();
};

#endif //_AREA_LIGHT_HPP_