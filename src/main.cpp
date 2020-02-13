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
    Sphere *testObjects = new Sphere[3];
    double origin = -0.02;
    for (size_t i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            testObjects[i].SetColor(png::rgba_pixel(0, 0, 255));
            break;
        case 1:
            testObjects[i].SetColor(png::rgba_pixel(0, 255, 0));
            break;
        case 2:
            testObjects[i].SetColor(png::rgba_pixel(255, 0, 0));
            break;
        default:
            break;
        }
        testObjects[i].SetOrigin({0.08, origin + i * std::abs(origin) , 0.0});
        testObjects[i].SetRadius(0.005);
        testScene.AddObject(&testObjects[i]);
    }

    // Step 3: Set ambient color and add lights to the scene
    testScene.SetAmbientColor({100, 100, 100, 255});
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
