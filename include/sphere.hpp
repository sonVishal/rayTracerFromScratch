// This class contains the representation of a discrete sphere.
#ifndef _SPHERE_HPP_
#define _SPHERE_HPP_

#include "vector.hpp"
#include "rgbcolor.hpp"

class Sphere
{
private:
    double m_radius{0.0};
    Vector3 m_origin{0.0};
    RGBColor m_diffuseColor{40};
public:
    Sphere();
    ~Sphere();
};

#endif