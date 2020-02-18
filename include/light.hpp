#ifndef _LIGHT_HPP_
#define _LIGHT_HPP_
#include "vector3.hpp"
#include <png++/rgb_pixel.hpp>

class Light
{
protected:
    Vector3 m_origin{0.0};
    double m_intensity{0.0};
    png::rgb_pixel m_color{255, 255, 255};

public:
    Light();
    Light(const Vector3 &t_origin);
    Light(const Vector3 &t_origin, double t_intensity);
    void SetIntensity(double t_intensity);
    double GetIntensity() const;
    virtual double GetIntensityAt(const Vector3& t_point) const = 0;
    void SetColor(const png::rgb_pixel &t_color);
    png::rgb_pixel GetColor() const;
    const Vector3& GetOrigin() const;
    virtual ~Light();
};

#endif //_LIGHT_HPP_