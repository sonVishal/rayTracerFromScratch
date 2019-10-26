#ifndef _CONSTANTS_HPP_
#define _CONSTANTS_HPP_
#include <limits>
#include <cmath>

constexpr double DOUBLE_EPS = std::numeric_limits<double>::epsilon();
constexpr double ABSOLUTE_TOL = DOUBLE_EPS * 100.0;
constexpr double FLOAT_EPS = std::numeric_limits<float>::epsilon();
constexpr double DOUBLE_MIN = std::numeric_limits<double>::min();

// Description: Function to check if two number t_a and t_b are equal
// with respect to an absolute tolerance of t_absTol and a relative
// tolerance of t_relTol.
// The absolute tolerance kicks in when t_a and t_b are small such that
// their multiplication with t_relTol results in an underflow.
// The relative tolerance kicks in when t_a and t_b are large.
// In this case t_a - t_b results in cancellation and thus we scale the
// relative tolerance with the larger of the two.
inline bool IsEq(double t_a, double t_b,
                 double t_absTol = ABSOLUTE_TOL,
                 double t_relTol = DOUBLE_EPS)
{
    return std::fabs(t_a - t_b) <= std::max(t_absTol, t_relTol * std::max(std::fabs(t_a), std::fabs(t_b)));
}

inline bool IsNe(double t_a, double t_b,
                 double t_absTol = ABSOLUTE_TOL,
                 double t_relTol = DOUBLE_EPS)
{
    return !IsEq(t_a, t_b, t_absTol, t_relTol);
}

inline bool IsGt(double t_a, double t_b,
                 double t_absTol = ABSOLUTE_TOL,
                 double t_relTol = DOUBLE_EPS)
{
    return std::fabs(t_a - t_b) > std::max(t_absTol, t_relTol * std::max(std::fabs(t_a), std::fabs(t_b)));
}

inline bool IsGe(double t_a, double t_b,
                 double t_absTol = ABSOLUTE_TOL,
                 double t_relTol = DOUBLE_EPS)
{
    return IsGt(t_a, t_b, t_absTol, t_relTol) || IsEq(t_a, t_b, t_absTol, t_relTol);
}

inline bool IsLt(double t_a, double t_b,
                 double t_absTol = ABSOLUTE_TOL,
                 double t_relTol = DOUBLE_EPS)
{
    return std::fabs(t_a - t_b) < std::max(t_absTol, t_relTol * std::max(std::fabs(t_a), std::fabs(t_b)));
}

inline bool IsLe(double t_a, double t_b,
                 double t_absTol = ABSOLUTE_TOL,
                 double t_relTol = DOUBLE_EPS)
{
    return IsLt(t_a, t_b, t_absTol, t_relTol) || IsEq(t_a, t_b, t_absTol, t_relTol);
}

#endif //_CONSTANTS_HPP_