#include "vector3.hpp"
#include <algorithm>
#include <cmath>

// Constructors
Vector3::Vector3()
{
}

Vector3::Vector3(double t_initVal) : m_coords{t_initVal}
{
}

Vector3::Vector3(double t_x, double t_y, double t_z) : m_coords{{t_x, t_y, t_z}}
{
}

// Copy and Assignment

// Move and Assignment

// Operators
Vector3 Vector3::operator+(const Vector3 &t_other) const
{
    return Vector3(
        m_coords[0] + t_other[0],
        m_coords[1] + t_other[1],
        m_coords[2] + t_other[2]);
}

Vector3 Vector3::operator-(const Vector3 &t_other) const
{
    return Vector3(
        m_coords[0] - t_other[0],
        m_coords[1] - t_other[1],
        m_coords[2] - t_other[2]);
}

void Vector3::operator+=(const Vector3 &t_other)
{
    m_coords[0] += t_other[0];
    m_coords[1] += t_other[1];
    m_coords[2] += t_other[2];
}

void Vector3::operator-=(const Vector3 &t_other)
{
    m_coords[0] -= t_other[0];
    m_coords[1] -= t_other[1];
    m_coords[2] -= t_other[2];
}

Vector3 Vector3::operator-() const
{
    return Vector3(
        -m_coords[0],
        -m_coords[1],
        -m_coords[2]);
}

// Scale
Vector3 Vector3::operator*(double t_scaleFactor) const
{
    return Vector3(
        t_scaleFactor * m_coords[0],
        t_scaleFactor * m_coords[1],
        t_scaleFactor * m_coords[2]);
}

Vector3 Vector3::operator/(double t_scaleFactor) const
{
    return Vector3(
        m_coords[0] / t_scaleFactor,
        m_coords[1] / t_scaleFactor,
        m_coords[2] / t_scaleFactor);
}

void Vector3::operator*=(double t_scaleFactor)
{
    m_coords[0] *= t_scaleFactor;
    m_coords[1] *= t_scaleFactor;
    m_coords[2] *= t_scaleFactor;
}

void Vector3::operator/=(double t_scaleFactor)
{
    m_coords[0] /= t_scaleFactor;
    m_coords[1] /= t_scaleFactor;
    m_coords[2] /= t_scaleFactor;
}

// Dot product
double Vector3::operator%(const Vector3 &t_other) const
{
    return (m_coords[0] * t_other[0]) +
           (m_coords[1] * t_other[1]) +
           (m_coords[2] * t_other[2]);
}

// Cross product
Vector3 Vector3::operator*(const Vector3 &t_other) const
{
    return Vector3(
        m_coords[1] * t_other[2] - m_coords[2] * t_other[1],
        m_coords[2] * t_other[0] - m_coords[0] * t_other[2],
        m_coords[0] * t_other[1] - m_coords[1] * t_other[0]);
}

// Other operators
void Vector3::Normalize()
{
    double mag = this->GetMagnitude();
    m_coords[0] /= mag;
    m_coords[1] /= mag;
    m_coords[2] /= mag;
}

// Getters
double &Vector3::GetCoordAt(unsigned int t_idx)
{
    return m_coords[t_idx];
}

double &Vector3::operator[](unsigned int t_idx)
{
    return m_coords[t_idx];
}

const double &Vector3::GetCoordAt(unsigned int t_idx) const
{
    return m_coords[t_idx];
}

const double &Vector3::operator[](unsigned int t_idx) const
{
    return m_coords[t_idx];
}

double Vector3::GetMagnitude() const
{
    return sqrt((m_coords[0] * m_coords[0]) +
                (m_coords[1] * m_coords[1]) +
                (m_coords[2] * m_coords[2]));
}

Vector3 Vector3::GetNormalized() const
{
    double mag = this->GetMagnitude();
    return Vector3(
        m_coords[0] / mag,
        m_coords[1] / mag,
        m_coords[2] / mag);
}

// Setters
void Vector3::SetCoordAt(unsigned int t_idx, double t_value)
{
    m_coords.at(t_idx) = t_value;
}

void Vector3::SetCoords(double t_x, double t_y, double t_z)
{
    m_coords[0] = t_x;
    m_coords[1] = t_y;
    m_coords[2] = t_z;
}

// Destuctor
Vector3::~Vector3() {}