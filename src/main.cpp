#include <iostream>
#include "sphere.hpp"
#include "rgbcolor.hpp"
#include "ppmwriter.hpp"
#include "scene.hpp"
#include "light.hpp"
#include "renderer.hpp"

// TODO: Define units!!!

int main(int argc, char const *argv[])
{
    PPMWriter outputImage;
    Sphere testSphere(Vector3{10.0, 0.0, 0.0}, 10.0);
    testSphere.SetColor(RGBColor{45, 45, 45});
    Light testLight(Vector3{0.0, 0.0, 10.0});

    Scene testScene;
    testScene.AddLight(testLight);
    testScene.AddObject(testSphere);

    Renderer testRenderer;
    testRenderer.SetScene(testScene);

    testRenderer.Render();

    outputImage.SetImage(testRenderer.GetRenderedImage());

    return 0;
}
