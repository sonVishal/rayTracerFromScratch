#ifndef _LIGHT_HPP_
#define _LIGHT_HPP_
#include "vector3.hpp"
#include <png++/rgb_pixel.hpp>

class Light
{
private:
    Vector3 m_origin{0.0};
    unsigned int m_intensity{0};
    png::rgb_pixel m_color{255, 255, 255};

public:
    Light();
    Light(const Vector3 &t_origin);
    Light(const Vector3& t_origin, unsigned int t_intensity);
    void SetIntensity(unsigned int t_intensity);
    unsigned int GetIntensity() const;
    void SetColor(const png::rgb_pixel& t_color);
    png::rgb_pixel GetColor() const;
    virtual ~Light();
};

#endif //_LIGHT_HPP_