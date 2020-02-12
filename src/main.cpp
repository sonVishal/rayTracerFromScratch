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
    Object *testObject = new Sphere();
    Vector3 objOrigin{0.08, 0.0, 0.0};
    testObject->SetColor(png::rgba_pixel(255, 0, 0));
    testObject->SetOrigin(objOrigin);
    static_cast<Sphere *>(testObject)->SetRadius(0.01);
    testScene.AddObject(testObject);
    testScene.SetAmbientColor(png::rgba_pixel(100, 100, 100));

    // Step 3: Add lights to the scene
    // Light *testLight = new Light(Vector3{0.0, 0.0, 0.01});
    // testScene.AddLight(testLight);

    // Step 4: Define what to render
    Renderer testRenderer;
    testRenderer.SetScene(testScene);

    // Step 5: Setup the camera
    Vector3 cameraUp, cameraOrigin{0.0, 0.0, 0.0},
        cameraView;
    cameraView = objOrigin - cameraOrigin;
    cameraUp = {0.0, 0.0, 1.0};
    Camera testCamera(cameraOrigin, cameraUp, cameraView);
    testRenderer.SetCamera(testCamera);

    // Setp 6: Setup the resolution and aspect ratio
    testRenderer.SetResolution(100); // N pixels in the height
    testRenderer.SetAspectRatio(16.0/9.0); // width:height

    // Step 7: Render!
    testRenderer.Render();

    // Step 7: Write the output to a file
    testRenderer.WriteRenderedImage("test_image.png");

    delete testObject;
    // delete testLight;
    return 0;
}
