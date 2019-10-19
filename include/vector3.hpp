#ifndef _VECTOR3_HPP_
#define _VECTOR3_HPP_

#include <array>
#include <initializer_list>

class Vector3
{
private:
    std::array<double, 3> m_coords{0.0};

public:
    // Constructors
    Vector3();
    Vector3(double t_initVal);
    Vector3(double t_x, double t_y, double t_z);

    // Copy and Assignment

    // Move and Assignment

    // Operators
    Vector3 operator+(const Vector3 &t_other) const;
    Vector3 operator-(const Vector3 &t_other) const;
    Vector3 operator-() const;
    void operator+=(const Vector3 &t_other);
    void operator-=(const Vector3 &t_other);
    // Scale
    Vector3 operator*(double t_scaleFactor) const;
    Vector3 operator/(double t_scaleFactor) const;
    void operator*=(double t_scaleFactor);
    void operator/=(double t_scaleFactor);
    // Dot product
    double operator%(const Vector3 &t_other) const;
    // Cross product
    Vector3 operator*(const Vector3 &t_other) const;

    // Other operators
    void Normalize();

    // Getters
    double &GetCoordAt(unsigned int t_idx);
    double &operator[](unsigned int t_idx);
    const double &GetCoordAt(unsigned int t_idx) const;
    const double &operator[](unsigned int t_idx) const;
    double GetMagnitude() const;
    Vector3 GetNormalized() const;

    // Setters
    void SetCoordAt(unsigned int t_idx, double t_value);
    void SetCoords(double t_x, double t_y, double t_z);

    ~Vector3();
};

#endif // _VECTOR3_HPP_