#ifndef _CAMERA_HPP_
#define _CAMERA_HPP_
#include "vector3.hpp"
#include <array>

class Camera
{
private:
    Vector3 m_origin{0.0},
        m_left{0.0},                // X, or Left when we look down the view direction
        m_up{0.0},                  // Y
        m_view{0.0};                // View direction is negative Z
    double m_focalLength{0.05};     // Default to 50mm lens
    double m_frameWidth{0.036};     // Default to 35mm film format
    double m_frameHeight{0.024};     // Default to 35mm film format
    double m_distToPlane{0.01};     // No user control required. This is fixed!

public:
    Camera() = default;
    Camera(const Vector3 &t_origin,
           const Vector3 &t_upDir,
           const Vector3 &t_viewDir);

    void SetFocalLength(double t_focalLength);
    void SetOrigin(Vector3 t_origin);
    void SetUpDirection(Vector3 t_upDir);
    void SetLeftDirection(Vector3 t_leftDir);
    void SetViewDirection(Vector3 t_viewDir);

    double GetFocalLength() const;
    const Vector3 GetOrigin() const;
    const Vector3 GetUpDirection() const;
    const Vector3 GetLeftDirection() const;
    const Vector3 GetViewDirection() const;

    Vector3 GetImagePlaneCenter() const;
    double GetImageWidth() const;
    double GetImageHeight() const;

    ~Camera() = default;
};

#endif //_CAMERA_HPP_