#ifndef _CAMERA_HPP_
#define _CAMERA_HPP_
#include "vector3.hpp"
#include <array>

class Camera
{
private:
    Vector3 m_origin{0.0},
        m_left{0.0},                              // X, or Left when we look down the view direction
        m_up{0.0},                                // Y
        m_view{0.0};                              // View direction is negative Z
    std::array<unsigned int, 2> m_resolution{10, 10}; // 0 - rows, 1 - columns

public:
    Camera() = default;
    Camera(const Vector3 &t_origin,
           const Vector3 &t_upDir,
           const Vector3 &t_viewDir);

    void SetFocalLength(unsigned int t_focalLength);
    void SetResolution(unsigned int t_xPixels, unsigned int t_yPixels);

    void GetResolution(unsigned int& t_xPixels, unsigned int& t_yPixels) const;
    void GetResolution(double& t_xPixels, double& t_yPixels) const;
    const Vector3 GetOrigin() const;
    const Vector3 GetUpDirection() const;
    const Vector3 GetLeftDirection() const;
    const Vector3 GetViewDirection() const;

    ~Camera() = default;
};

#endif //_CAMERA_HPP_