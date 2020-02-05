#ifndef _VECTOR3_HPP_
#define _VECTOR3_HPP_
#include <array>
#include <initializer_list>
#include <iostream>

class Vector3
{
private:
    std::array<double, 3> m_coords{0.0};

public:
    // Constructors
    Vector3() = default;
    Vector3(double t_initVal);
    Vector3(double t_x, double t_y, double t_z);

    // Operators
    // Binary
    Vector3 operator+(const Vector3 &t_other) const;
    Vector3 operator-(const Vector3 &t_other) const;
    // Unary
    Vector3 operator+() const;
    Vector3 operator-() const;
    // Scalar operators
    Vector3 operator*(double t_scaleFactor) const;
    Vector3 operator/(double t_scaleFactor) const;
    // Dot product
    double operator%(const Vector3 &t_other) const;
    // Cross product
    Vector3 operator*(const Vector3 &t_other) const;
    // Assignment
    Vector3 &operator+=(const Vector3 &t_other);
    Vector3 &operator-=(const Vector3 &t_other);
    Vector3 &operator*=(double t_scaleFactor);
    Vector3 &operator/=(double t_scaleFactor);
    // Access
    const double &operator[](unsigned int t_idx) const;
    double &operator[](unsigned int t_idx);
    // Equality
    bool operator==(const Vector3 &t_other) const;
    bool operator!=(const Vector3 &t_other) const;

    // Other operators
    void Normalize();

    // Getters
    double &GetCoordAt(unsigned int t_idx);
    const double &GetCoordAt(unsigned int t_idx) const;
    double GetMagnitude() const;
    double GetMagnitudeSq() const;
    Vector3 GetNormalized() const;

    // Setters
    void SetCoordAt(unsigned int t_idx, double t_value);
    void SetCoords(double t_x, double t_y, double t_z);

    // Printers
    friend std::ostream &operator<<(std::ostream &t_output, const Vector3 &t_vec);

    ~Vector3() = default;
};

#endif // _VECTOR3_HPP_