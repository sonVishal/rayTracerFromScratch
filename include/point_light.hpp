#ifndef _POINT_LIGHT_HPP_
#define _POINT_LIGHT_HPP_
#include "light.hpp"

class PointLight : public Light
{
public:
    PointLight();
    PointLight(const Vector3 &t_origin);
    PointLight(const Vector3 &t_origin, double t_intensity);
    double GetIntensityAt(const Vector3& t_point) const;
    ~PointLight();
};

#endif //_POINT_LIGHT_HPP_