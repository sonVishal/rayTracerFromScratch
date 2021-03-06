#ifndef _CAMERA_HPP_
#define _CAMERA_HPP_
#include "vector.hpp"
#include <array>

class Camera
{
private:
    Vector3 m_origin{0.0},
        m_left{0.0},                              // X, or Left when we look down the view direction
        m_up{0.0},                                // Y
        m_view{0.0};                              // View direction is negative Z
    std::array<unsigned int, 2> m_resolution{10}; // 0 - rows, 1 - columns
    unsigned int m_focalLength{50};               // defines at what distance is the view plane from position
public:
    Camera();
    Camera(const Vector3 &t_origin,
           const Vector3 &t_upDir,
           const Vector3 &t_viewDir);

    void SetFocalLength(unsigned int t_focalLength);
    void SetResolution(unsigned int t_xPixels, unsigned int t_yPixels);

    ~Camera();
};

#endif //_CAMERA_HPP_