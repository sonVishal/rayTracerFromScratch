#include <iostream>
#include "sphere.hpp"
#include "scene.hpp"
#include "light.hpp"
#include "renderer.hpp"
#include "camera.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <png++/png.hpp>

// Everything is in millimeters!!!
// Only support rectilinear lenses!!!

int main(int argc, char const *argv[])
{
    // Step 1: Define the scene
    Scene testScene;

    // Step 2: Add objects to the scene
    Sphere *testObjects = new Sphere[2];

    testObjects[0].SetColor(png::rgba_pixel(255, 0, 0));
    testObjects[0].SetOrigin({0.08, 0.0, 0.0});
    testObjects[0].SetRadius(0.01);

    testObjects[1].SetColor(png::rgba_pixel(0, 255, 0));
    testObjects[1].SetOrigin({0.08, 0.01, 0.0});
    testObjects[1].SetRadius(0.01);

    for (size_t i = 0; i < 2; i++)
    {
        testScene.AddObject(&testObjects[i]);
    }

    testScene.SetAmbientColor({100, 100, 100, 255});

    // Step 3: Add lights to the scene
    // Light *testLight = new Light(Vector3{0.0, 0.0, 0.01});
    // testScene.AddLight(testLight);

    // Step 4: Define what to render
    Renderer testRenderer;
    testRenderer.SetScene(testScene);

    // Step 5: Setup the camera
    Vector3 cameraUp, cameraOrigin{0.0, 0.0, 0.0},
        cameraView;
    cameraView = {1.0, 0.0, 0.0};
    cameraUp = {0.0, 0.0, 1.0};
    Camera testCamera(cameraOrigin, cameraUp, cameraView);
    testRenderer.SetCamera(testCamera);

    // Setp 6: Setup the resolution and aspect ratio
    testRenderer.SetResolution(100);         // N pixels in the height
    testRenderer.SetAspectRatio(16.0 / 9.0); // width:height

    // Step 7: Render!
    testRenderer.Render();

    // Step 7: Write the output to a file
    testRenderer.WriteRenderedImage("test_image.png");

    delete[] testObjects;
    // delete testLight;
    return 0;
}
