#include "camera.hpp"

Camera::Camera(const Vector3 &t_origin, const Vector3 &t_upDirection,
               const Vector3 &t_viewDirection)
    : m_origin{t_origin},
      m_up{t_upDirection},
      m_view{t_viewDirection}
{
    m_left = m_up * (-m_view);
}

void Camera::SetFocalLength(unsigned int t_focalLength)
{
    m_focalLength = t_focalLength;
}

void Camera::SetResolution(unsigned int t_xPixels, unsigned int t_yPixels)
{
    m_resolution[0] = t_xPixels;
    m_resolution[1] = t_yPixels;
}