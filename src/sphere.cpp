#include "sphere.hpp"

Sphere::Sphere() : uSubDiv(10), vSubDiv(10), radius(1.0)
{
    this->origin[0] = 0.0;
    this->origin[1] = 0.0;
    this->origin[1] = 0.0;
}

Sphere::~Sphere()
{
}
