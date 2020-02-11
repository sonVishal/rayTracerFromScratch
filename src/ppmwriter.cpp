#include "ppmwriter.hpp"
#include "rgbcolor.hpp"
#include <fstream>
#include <iostream>

const std::string PPMWriter::m_fileType = "P6";

PPMWriter::PPMWriter(const char *t_fileName) : m_fileName(t_fileName)
{
}

void PPMWriter::SetFileName(const char *t_fileName)
{
    m_fileName.clear();
    m_fileName.assign(t_fileName);
}

void PPMWriter::SetImageSize(unsigned int t_rows, unsigned int t_columns)
{
    m_height = t_rows;
    m_width = t_columns;
}

void PPMWriter::SetImage(const RGBImage &t_image)
{
    m_pixelMatrix = t_image;
}

void PPMWriter::WritePixel(std::ofstream &t_fileStream, const RGBColor &t_pixelValue)
{
    uint8_t colorAsBytes[3] = {0, 0, 0};
    unsigned int colorRGB[3] = {t_pixelValue.GetRed(), t_pixelValue.GetGreen(), t_pixelValue.GetBlue()};

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            uint8_t bitMask = (1 << j);
            if (colorRGB[i] & bitMask)
            {
                colorAsBytes[i] |= bitMask;
            }
        }
    }

    t_fileStream << colorAsBytes[0] << colorAsBytes[1] << colorAsBytes[2];
}

void PPMWriter::SetFileComment(const char *t_fileComment)
{
    this->m_fileComment.clear();
    this->m_fileComment.assign(t_fileComment);
}

void PPMWriter::WriteImage()
{
    if (m_width * m_height != m_pixelMatrix.size())
    {
        std::cerr << "Matrix does not contain enough elements\n";
        return;
    }

    this->m_width = this->m_height = 100;

    std::ofstream imageFile;
    imageFile.open(m_fileName, std::ios_base::out | std::ios_base::binary);

    imageFile << PPMWriter::m_fileType << '\n';
    imageFile << std::to_string(this->m_width) << '\n';
    imageFile << std::to_string(this->m_height) << '\n';
    imageFile << std::to_string(RGBColor::GetMaxValue()) << '\n';

    auto currentPixel = this->m_pixelMatrix.begin();
    auto pixelEnd = this->m_pixelMatrix.end();
    for (unsigned int i = 0; (i < this->m_height) && (currentPixel != pixelEnd); i++)
    {
        for (unsigned int j = 0; j < (this->m_width) && (currentPixel != pixelEnd); j++)
        {
            PPMWriter::WritePixel(imageFile, *currentPixel);
            std::advance(currentPixel, 1);
        }
    }

    imageFile.close();
}
