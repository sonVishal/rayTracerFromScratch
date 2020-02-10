#include "camera.hpp"
#include <cmath>

Camera::Camera(const Vector3 &t_origin, const Vector3 &t_upDirection,
               const Vector3 &t_viewDirection)
    : m_origin{t_origin},
      m_up{t_upDirection},
      m_view{t_viewDirection}
{
    m_up.Normalize();
    m_view.Normalize();
    m_left = (-m_view) * m_up;
    m_left.Normalize();
}

void Camera::SetOrigin(Vector3 t_origin)
{
    m_origin = t_origin;
}
void Camera::SetUpDirection(Vector3 t_upDir)
{
    m_up = t_upDir;
    m_up.Normalize();
}
void Camera::SetLeftDirection(Vector3 t_leftDir)
{
    m_left = t_leftDir;
    m_left.Normalize();
}
void Camera::SetViewDirection(Vector3 t_viewDir)
{
    m_view = t_viewDir;
    m_view.Normalize();
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

void Camera::SetFocalLength(double t_focalLength)
{
    m_focalLength = t_focalLength;
}

void Camera::SetFrameSize(double t_frameSize)
{
    m_frameSize = t_frameSize;
}

double Camera::GetFocalLength() const
{
    return m_focalLength;
}

double Camera::GetFrameSize() const
{
    return m_frameSize;
}

double Camera::GetFieldOfView() const
{
    return (2.0 * atan(m_frameSize * 0.5 / m_focalLength));
}

double Camera::GetImageWidth() const
{
    return (m_distToPlane * (m_frameSize * 0.5 / m_focalLength));
}

Vector3 Camera::GetImagePlaneCenter() const
{
    return (m_origin + (m_view * m_distToPlane));
}