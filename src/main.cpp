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

// TODO: Define units!!!

int main(int argc, char const *argv[])
{
    // Step 1: Define the scene
    Scene testScene;

    // Step 2: Add objects to the scene
    int nObjs = 1;
    Object **testObjs = new Object*[nObjs];
    double radius = 4.0;
    for (int i = 0; i < nObjs; i++)
    {
        testObjs[i] = new Sphere;
        std::array<unsigned int, 3> objColor = {0, 0, 0};
        objColor.at(i) = 255;
        testObjs[i]->SetColor(objColor);
        static_cast<Sphere *>(testObjs[i])->SetRadius(radius);
        // double angle = M_PI_2 + i * M_PI / 3;
        testObjs[i]->SetOrigin({100.0, 0.0, 0.0});

        testScene.AddObject(testObjs[i]);
    }
    // testScene.AddObjects(3, testObjs);

    // Step 3: Add lights to the scene
    Light *testLight = new Light(Vector3{0.0, 0.0, 10.0});
    testScene.AddLight(testLight);

    // Step 4: Define what to render
    Renderer testRenderer;
    testRenderer.SetScene(testScene);

    // Step 5: Setup the camera
    Vector3 cameraUp, cameraOrigin,
        cameraView{100.0, 0.0, 0.0};
    cameraUp.SetCoordAt(2, 1.0);
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

    for (int i = 0; i < nObjs; i++)
    {
        delete testObjs[i];
    }
    delete[] testObjs;
    delete testLight;
    return 0;
}
