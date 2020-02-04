#include "camera.hpp"

Camera::Camera(const Vector3 &t_origin, const Vector3 &t_upDirection,
               const Vector3 &t_viewDirection)
    : m_origin{t_origin},
      m_up{t_upDirection},
      m_view{t_viewDirection}
{
    m_left = m_up * (-m_view);
}

void Camera::GetResolution(unsigned int& t_xPixels, unsigned int& t_yPixels) const
{
    t_xPixels = m_resolution[0];
    t_yPixels = m_resolution[1];
}

void Camera::SetResolution(unsigned int t_xPixels, unsigned int t_yPixels)
{
    m_resolution[0] = t_xPixels;
    m_resolution[1] = t_yPixels;
}

const Vector3 Camera::GetOrigin() const
{
    return m_origin;
}

const Vector3 Camera::GetUpDirection() const
{
    return m_up;
}

const Vector3 Camera::GetLeftDirection() const
{
    return m_left;
}

const Vector3 Camera::GetViewDirection() const
{
    return m_view;
}
