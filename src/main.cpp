#include <iostream>
#include "sphere.hpp"
#include "rgbcolor.hpp"
#include "ppmwriter.hpp"
#include "scene.hpp"
#include "light.hpp"
#include "renderer.hpp"
#include "camera.hpp"

// TODO: Define units!!!

int main(int argc, char const *argv[])
{
    // Step 1: Define the scene
    Scene testScene;
    // Step 2: Add objects to the scene
    Sphere testSphere(Vector3{10.0, 0.0, 0.0}, 10.0);
    testSphere.SetColor(RGBColor{45, 45, 45});
    testScene.AddObject(testSphere);
    // Step 3: Add lights to the scene
    Light testLight(Vector3{0.0, 0.0, 10.0});
    testScene.AddLight(testLight);
    // Step 4: Define what to render
    Renderer testRenderer;
    testRenderer.SetScene(testScene);
    // Step 5: Setup the camera
    Vector3 cameraUp, cameraOrigin, cameraView;
    cameraUp.SetCoordAt(2, 1.0);
    cameraView = testSphere.GetOrigin() - cameraOrigin;
    Camera testCamera(cameraOrigin, cameraUp, cameraView);
    testCamera.SetResolution(100, 100);
    testRenderer.SetCamera(testCamera);
    // Step 6: Render!
    testRenderer.Render();
    // Step 7: Write the output to a file
    PPMWriter outputImage;
    outputImage.SetImage(testRenderer.GetRenderedImage());
    unsigned int res[2];
    testCamera.GetResolution(res[0], res[1]);
    outputImage.SetImageSize(res[0], res[1]);
    outputImage.SetFileName("testImage.ppm");
    outputImage.WriteImage();
    return 0;
}
