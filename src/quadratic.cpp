#include "quadratic.hpp"
#include <iostream>
#include <iomanip>
#include <ios>
#include <cmath>
#include <limits>

QuadraticEq::QuadraticEq(/* args */)
{
}

QuadraticEq::~QuadraticEq()
{
}

// ax² + bx + c = 0 form
void QuadraticEq::SetEquation(double t_a, double t_b, double t_c)
{
    m_coeffs.at(0) = t_a;
    m_coeffs.at(1) = t_b;
    m_coeffs.at(2) = t_c;
}

double QuadraticEq::CalculateDeterminant() const
{
    double bSq = m_coeffs.at(1) * m_coeffs.at(1);
    double ac4 = 4 * m_coeffs.at(0) * m_coeffs.at(2);
    return bSq - ac4;
}

int QuadraticEq::GetNumberOfRoots() const
{
    const double determinant = CalculateDeterminant();
    int numRoots = 0;
    if (determinant == 0.0)
    {
        numRoots = 1;
    }
    else if (determinant > 0.0)
    {
        numRoots = 2;
    }
    return numRoots;
}

int QuadraticEq::CalculateRoots()
{
    const double determinant = CalculateDeterminant();
    int numRoots = 0;
    if (determinant == 0.0)
    {
        m_roots.at(0) = -m_coeffs.at(1) * 0.5 / m_coeffs.at(0);
        m_roots.at(1) = m_roots.at(0);
        numRoots = 1;
    }
    else if (determinant > 0.0)
    {
        double tmpRes = std::fabs(m_coeffs.at(1)) + sqrt(determinant);
        tmpRes *= std::signbit(m_coeffs.at(1)) ? 1.0 : -1.0;
        m_roots.at(0) = tmpRes * 0.5 / m_coeffs.at(0);
        m_roots.at(1) = 2.0 * m_coeffs.at(2) / tmpRes;
        if (m_roots.at(0) > m_roots.at(1))
        {
            std::swap(m_roots.at(0), m_roots.at(1));
        }
        numRoots = 2;
    }
    else // negative determinant
    {
        numRoots = 0;
        m_roots.at(0) = m_roots.at(1) = std::numeric_limits<double>::quiet_NaN();
    }
    return numRoots;
}

const std::array<double, 2>& QuadraticEq::GetRoots() const
{
    return m_roots;
}

double QuadraticEq::GetDeterminant() const
{
    return CalculateDeterminant();
}

void QuadraticEq::PrintEquation() const
{
    std::streamsize ss = std::cout.precision();
    std::cout << std::setprecision(4)\
    << "Solving: " << m_coeffs.at(0) << "x^2 "\
    << std::showpos << m_coeffs.at(1) << "x "\
    << m_coeffs.at(2) << " = 0\n";
    std::cout << std::noshowpos << std::setprecision(ss);
}