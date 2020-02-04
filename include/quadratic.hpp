#ifndef _QUADRATIC_HXX_
#define _QUADRATIC_HXX_
#include <array>
#include <memory>
#include <cmath>

class QuadraticEq
{
private:
    std::array<double, 3> m_coeffs{0.0};
    std::array<double, 2> m_roots{std::nan("0.0")};
    int m_numRoots{0};
    double CalculateDeterminant() const;
public:
    QuadraticEq();
    // ax² + bx + c = 0 form
    void SetEquation(double t_a, double t_b, double t_c);
    // Calculates the roots and returns number of roots.
    int CalculateRoots();
    // Gets the number of roots and does not calculate
    int GetNumberOfRoots() const;
    const std::array<double, 2>& GetRoots() const;
    double GetDeterminant() const;
    void PrintEquation() const;
    ~QuadraticEq();
};

#endif