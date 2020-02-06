#include "vector3.hpp"
#include "constants.hpp"
#include <algorithm>
#include <cmath>

// Non-default Constructors
Vector3::Vector3(double t_initVal) : m_coords{t_initVal}
{
}

Vector3::Vector3(double t_x, double t_y, double t_z) : m_coords{{t_x, t_y, t_z}}
{
}

// Operators
// Binary
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
// Unary
Vector3 Vector3::operator+() const
{
    return Vector3(
        m_coords[0],
        m_coords[1],
        m_coords[2]);
}
Vector3 Vector3::operator-() const
{
    return Vector3(
        -m_coords[0],
        -m_coords[1],
        -m_coords[2]);
}

// Scalar operators
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

// Assignment
Vector3 &Vector3::operator+=(const Vector3 &t_other)
{
    m_coords[0] += t_other[0];
    m_coords[1] += t_other[1];
    m_coords[2] += t_other[2];
    return *this;
}

Vector3 &Vector3::operator-=(const Vector3 &t_other)
{
    m_coords[0] -= t_other[0];
    m_coords[1] -= t_other[1];
    m_coords[2] -= t_other[2];
    return *this;
}

Vector3 &Vector3::operator*=(double t_scaleFactor)
{
    m_coords[0] *= t_scaleFactor;
    m_coords[1] *= t_scaleFactor;
    m_coords[2] *= t_scaleFactor;
    return *this;
}

Vector3 &Vector3::operator/=(double t_scaleFactor)
{
    m_coords[0] /= t_scaleFactor;
    m_coords[1] /= t_scaleFactor;
    m_coords[2] /= t_scaleFactor;
    return *this;
}

// Access
double &Vector3::operator[](unsigned int t_idx)
{
    return m_coords[t_idx];
}

const double &Vector3::operator[](unsigned int t_idx) const
{
    return m_coords[t_idx];
}

// Equality
bool Vector3::operator==(const Vector3 &t_other) const
{
    return IsEq(m_coords[0], t_other[0]) &&
           IsEq(m_coords[1], t_other[1]) &&
           IsEq(m_coords[2], t_other[2]);
}

bool Vector3::operator!=(const Vector3 &t_other) const
{
    return IsNe(m_coords[0], t_other[0]) &&
           IsNe(m_coords[1], t_other[1]) &&
           IsNe(m_coords[2], t_other[2]);
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

const double &Vector3::GetCoordAt(unsigned int t_idx) const
{
    return m_coords[t_idx];
}

double Vector3::GetMagnitude() const
{
    return sqrt((m_coords[0] * m_coords[0]) +
                (m_coords[1] * m_coords[1]) +
                (m_coords[2] * m_coords[2]));
}

double Vector3::GetMagnitudeSq() const
{
    return (m_coords[0] * m_coords[0]) +
           (m_coords[1] * m_coords[1]) +
           (m_coords[2] * m_coords[2]);
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

// Printers
std::ostream &operator<<(std::ostream &t_output, const Vector3 &t_vec)
{
    t_output << t_vec[0] << ',' << t_vec[1] << ',' << t_vec[2];
    return t_output;
}