#ifndef _RGBCOLOR_H_
#define _RGBCOLOR_H_

#include <array>
#include <algorithm>

class RGBColor
{
private:
    std::array<int, 3> m_color{0, 0, 0};
    static const int m_maxValue;
    // Caps the input value to 0-255.
    // If negative then caps it to 0.
    // If > 255 then caps it to 255.
    static int GetCappedValue(int t_value);
public:
    // Constructors
    RGBColor() = default;

    RGBColor(int t_red, int t_green, int t_blue) :
    m_color{{t_red, t_green, t_blue}}
    { }

    RGBColor(const std::array<int, 3>& t_color) :
    m_color{t_color}
    { }

    ~RGBColor() = default;

    // Getters
    int GetRed() const {
        return m_color.at(0);
    }

    int GetGreen() const {
        return m_color.at(1);
    }

    int GetBlue() const {
        return m_color.at(2);
    }

    const std::array<int, 3>& GetColor() const {
        return m_color;
    }

    static int GetMaxValue()
    {
        return RGBColor::m_maxValue;
    }

    // Setters
    void SetRed(const int& t_red) {
        m_color.at(0) = t_red;
    }

    void SetGreen(const int& t_green) {
        m_color.at(1) = t_green;
    }

    void SetBlue(const int& t_blue) {
        m_color.at(2) = t_blue;
    }

    void SetColor(const std::array<int, 3>& t_color) {
        std::copy(t_color.begin(), t_color.end(),
            m_color.begin());
    }

    // Operators
    RGBColor& operator+(const RGBColor& t_other);
    RGBColor& operator-(const RGBColor& t_other);
    RGBColor& operator*(const RGBColor& t_other);
    RGBColor& operator*(const int& t_scalar);
    RGBColor& operator/(const int& t_scalar);
};

#endif //_RGBCOLOR_H_