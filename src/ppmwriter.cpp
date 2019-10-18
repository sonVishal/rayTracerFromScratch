#include "ppmwriter.hpp"
#include "rgbcolor.hpp"
#include <fstream>
#include <iostream>

const std::string PPMWriter::m_fileType = "P3\n";

PPMWriter::PPMWriter(const char* t_fileName) : m_fileName(t_fileName)
{}

void PPMWriter::SetFileName(const char* t_fileName)
{
    m_fileName.clear();
    m_fileName.assign(t_fileName);
}

void PPMWriter::SetImageSize(unsigned int t_rows, unsigned int t_columns)
{
    m_numRows = t_rows;
    m_numColumns = t_columns;
}

void PPMWriter::SetImage(const PPMWriter::RGBVector& t_image)
{
    m_pixelMatrix = t_image;
}

void PPMWriter::WritePixel(std::ofstream& t_fileStream, const RGBColor& t_pixelValue)
 {
    t_fileStream << t_pixelValue.GetRed() << ' ' <<\
        t_pixelValue.GetGreen() << ' ' <<\
        t_pixelValue.GetBlue();
}

void PPMWriter::SetFileComment(const char* t_fileComment)
{
    this->m_fileComment.clear();
    this->m_fileComment.assign(t_fileComment);
}

void PPMWriter::WriteImage()
{
    if (m_numColumns * m_numRows != m_pixelMatrix.size())
    {
        std::cerr << "Matrix does not contain enough elements\n";
        return;
    }

    std::ofstream imageFile;
    imageFile.open(m_fileName, std::ios_base::out);

    imageFile << PPMWriter::m_fileType;
    imageFile << this->m_fileComment;
    imageFile << this->m_numRows << ' ' << this->m_numColumns << '\n';
    imageFile << RGBColor::GetMaxValue() << '\n';

    auto currentPixel = this->m_pixelMatrix.begin();
    auto pixelEnd = this->m_pixelMatrix.end();
    for (unsigned int i = 0; (i < this->m_numRows) && (currentPixel != pixelEnd); i++)
    {
        for (unsigned int j = 0; j < (this->m_numColumns) && (currentPixel != pixelEnd); j++)
        {
            PPMWriter::WritePixel(imageFile, *currentPixel);
            // After each pixel put two spaces for readability
            imageFile << "  ";
            std::advance(currentPixel, 1);
        }
        imageFile << '\n';
    }

    imageFile.close();
}
