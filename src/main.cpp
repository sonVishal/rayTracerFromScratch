#include <iostream>
#include "sphere.hpp"
#include "ppmwriter.hpp"

int main(int argc, char const *argv[])
{
    PPMWriter outputImage();
    Sphere s(RGBColor{45});

    std::cout << "Test\n";
    return 0;
}
