#ifndef _PPMWRITER_H_
#define _PPMWRITER_H_

#include <vector>
#include <tuple>
#include <string>
#include <fstream>

class RGBColor;

class PPMWriter
{
public:
    using RGBVector = std::vector<RGBColor>;
    PPMWriter() = default;
    ~PPMWriter() = default;
    void WriteImage();
    void SetFileComment(const char* t_fileComment);
    void SetFileName(const char* t_fileName);
    void SetImageSize(int t_rows, int t_columns);
    void SetImage(const RGBVector& t_image);

private:
    int m_numRows{1};
    int m_numColumns{1};
    RGBVector m_pixelMatrix;
    static const std::string m_fileType;
    std::string m_fileComment{"# This file has been written by PPMWriter v0.0.1\n"};
    std::string m_fileName{"./image.ppm"};
    static void WritePixel(std::ofstream& t_fileStream, const RGBColor& t_pixelValue);
};

#endif