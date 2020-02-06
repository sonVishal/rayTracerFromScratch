#ifndef _RGBCOLOR_H_
#define _RGBCOLOR_H_

#include <array>
#include <algorithm>
#include <vector>
#include <iostream>

class RGBColor
{
private:
    std::array<unsigned int, 3> m_color{0, 0, 0};
    static const unsigned int m_maxValue;
    // Caps the input value to 0-255.
    // If negative then caps it to 0.
    // If > 255 then caps it to 255.
    static unsigned int GetCappedValue(unsigned int t_value);

public:
    // Constructors
    RGBColor() = default;

    RGBColor(unsigned int t_grayValue) : m_color{t_grayValue}
    {
    }

    RGBColor(unsigned int t_red, unsigned int t_green, unsigned int t_blue) : m_color{{t_red, t_green, t_blue}}
    {
    }

    RGBColor(const std::array<unsigned int, 3> &t_color) : m_color{t_color}
    {
    }

    RGBColor(const RGBColor& t_other)
    {
        this->SetRed(t_other.GetRed());
        this->SetGreen(t_other.GetGreen());
        this->SetBlue(t_other.GetBlue());
    }

    ~RGBColor() = default;

    // Getters
    unsigned int GetRed() const
    {
        return m_color.at(0);
    }

    unsigned int GetGreen() const
    {
        return m_color.at(1);
    }

    unsigned int GetBlue() const
    {
        return m_color.at(2);
    }

    const std::array<unsigned int, 3> &GetColor() const
    {
        return m_color;
    }

    static unsigned int GetMaxValue()
    {
        return RGBColor::m_maxValue;
    }

    // Setters
    void SetRed(const unsigned int &t_red)
    {
        m_color.at(0) = t_red;
    }

    void SetGreen(const unsigned int &t_green)
    {
        m_color.at(1) = t_green;
    }

    void SetBlue(const unsigned int &t_blue)
    {
        m_color.at(2) = t_blue;
    }

    void SetColor(const std::array<unsigned int, 3> &t_color)
    {
        std::copy(t_color.begin(), t_color.end(),
                  m_color.begin());
    }

    // Operators
    RGBColor &operator+(const RGBColor &t_other);
    RGBColor &operator-(const RGBColor &t_other);
    RGBColor &operator*(const RGBColor &t_other);
    RGBColor &operator*(const unsigned int &t_scalar);
    RGBColor &operator/(const unsigned int &t_scalar);

    // Printers
    friend std::ostream &operator<<(std::ostream &t_output, const RGBColor &t_color);

};

using RGBImage = std::vector<RGBColor>;
#endif //_RGBCOLOR_H_