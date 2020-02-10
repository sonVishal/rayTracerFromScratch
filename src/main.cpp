#include <iostream>
#include "sphere.hpp"
#include "rgbcolor.hpp"
#include "ppmwriter.hpp"
#include "scene.hpp"
#include "light.hpp"
#include "renderer.hpp"
#include "camera.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

// Everything is in meters!!!
// Only support rectilinear lenses!!!

int main(int argc, char const *argv[])
{
    // Step 1: Define the scene
    Scene testScene;

    // Step 2: Add objects to the scene
    Object *testObject = new Sphere();
    testObject->SetColor(RGBColor(45, 45, 45));
    testObject->SetOrigin(Vector3(0.04, 0.0, 0.0));
    static_cast<Sphere *>(testObject)->SetRadius(0.01);
    testScene.AddObject(testObject);

    // Step 3: Add lights to the scene
    Light *testLight = new Light(Vector3{0.0, 0.0, 0.01});
    testScene.AddLight(testLight);

    // Step 4: Define what to render
    Renderer testRenderer;
    testRenderer.SetScene(testScene);

    // Step 5: Setup the camera
    Vector3 cameraUp, cameraOrigin,
        cameraView{0.04, 0.0, 0.0};
    cameraUp.SetCoordAt(2, 1.0);
    Camera testCamera(cameraOrigin, cameraUp, cameraView);
    testRenderer.SetCamera(testCamera);

    // Setp 6: Setup the resolution
    testRenderer.SetResolution(100); // N pixels in the longest dir

    // Step 7: Render!
    testRenderer.Render();

    // Step 7: Write the output to a file
    // PPMWriter outputImage;
    // outputImage.SetImage(testRenderer.GetRenderedImage());
    // outputImage.SetImageSize(res[0], res[1]);
    // outputImage.SetFileName("testImage.ppm");
    // outputImage.WriteImage();

    delete testObject;
    delete testLight;
    return 0;
}
