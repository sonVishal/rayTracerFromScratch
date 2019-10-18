#include "rgbcolor.hpp"

const int RGBColor::m_maxValue = 255;

int RGBColor::GetCappedValue(int t_value)
{
    return std::min(std::max(t_value, 0), RGBColor::m_maxValue);
}

// Operators
RGBColor& RGBColor::operator+(const RGBColor& t_other)
{
    const std::array<int, 3>& otherColor = t_other.GetColor();
    m_color.at(0) = RGBColor::GetCappedValue(m_color.at(0) + otherColor.at(0));
    m_color.at(1) = RGBColor::GetCappedValue(m_color.at(1) + otherColor.at(1));
    m_color.at(2) = RGBColor::GetCappedValue(m_color.at(2) + otherColor.at(2));
    return *this;
}

RGBColor& RGBColor::operator-(const RGBColor& t_other)
{
    const std::array<int, 3>& otherColor = t_other.GetColor();
    m_color.at(0) = RGBColor::GetCappedValue(m_color.at(0) - otherColor.at(0));
    m_color.at(1) = RGBColor::GetCappedValue(m_color.at(1) - otherColor.at(1));
    m_color.at(2) = RGBColor::GetCappedValue(m_color.at(2) - otherColor.at(2));
    return *this;
}

RGBColor& RGBColor::operator*(const RGBColor& t_other)
{
    const std::array<int, 3>& otherColor = t_other.GetColor();
    m_color.at(0) = RGBColor::GetCappedValue(m_color.at(0) * otherColor.at(0));
    m_color.at(1) = RGBColor::GetCappedValue(m_color.at(1) * otherColor.at(1));
    m_color.at(2) = RGBColor::GetCappedValue(m_color.at(2) * otherColor.at(2));
    return *this;
}

RGBColor& RGBColor::operator*(const int& t_scalar)
{
    m_color.at(0) = RGBColor::GetCappedValue(m_color.at(0) * t_scalar);
    m_color.at(1) = RGBColor::GetCappedValue(m_color.at(1) * t_scalar);
    m_color.at(2) = RGBColor::GetCappedValue(m_color.at(2) * t_scalar);
    return *this;
}

RGBColor& RGBColor::operator/(const int& t_scalar)
{
    // In case t_scalar is 0 all the components will get capped to 255
    m_color.at(0) = RGBColor::GetCappedValue(m_color.at(0) / t_scalar);
    m_color.at(1) = RGBColor::GetCappedValue(m_color.at(1) / t_scalar);
    m_color.at(2) = RGBColor::GetCappedValue(m_color.at(2) / t_scalar);
    return *this;
}
