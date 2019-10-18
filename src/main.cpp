#include <iostream>
#include "sphere.hpp"
#include "rgbcolor.hpp"
#include "ppmwriter.hpp"

// TODO: Define units!!!

int main(int argc, char const *argv[])
{
    PPMWriter outputImage();
    Sphere s(RGBColor{45});

    return 0;
}
