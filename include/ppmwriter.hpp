#ifndef _PPMWRITER_H_
#define _PPMWRITER_H_

#include <vector>
#include <tuple>
#include <string>
#include <fstream>
#include "rgbcolor.hpp"

class PPMWriter
{
public:
    PPMWriter() = default;
    PPMWriter(const char *t_fileName);
    ~PPMWriter() = default;
    void WriteImage();
    void SetFileComment(const char *t_fileComment);
    void SetFileName(const char *t_fileName);
    void SetImageSize(unsigned int t_rows, unsigned int t_columns);
    void SetImage(const RGBImage &t_image);

private:
    unsigned int m_numRows{1};
    unsigned int m_numColumns{1};
    RGBImage m_pixelMatrix;
    static const std::string m_fileType;
    std::string m_fileComment{"# This file has been written by PPMWriter v0.0.1\n"};
    std::string m_fileName{"./image.ppm"};
    static void WritePixel(std::ofstream &t_fileStream, const RGBColor &t_pixelValue);
};

#endif