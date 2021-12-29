#include "ImageConverter.h"
#include "PCH.h"
std::string ImageConverter::ConvertImageToCode(cv::Mat InMat) const
{
    const int& samples_count = InMat.rows;
    int step = std::ceil(InMat.cols / samples_count);
    if (step == 0)
        step = 1;
    int started_index = 0;
    for (int i = 0; i<InMat.cols; i++) {
        uchar pixel_value = InMat.at<uchar>(samples_count / 2, i);
        if (pixel_value < 126) {
            started_index = i;
            break;
        }
    }
    std::stringstream sstream;
    for (int i = started_index; i < InMat.cols; i+=step) {
        uchar pixel_value = InMat.at<uchar>(samples_count / 2, i);
        if (pixel_value < 126)
            sstream << 1;
        else
            sstream << 0;
    }
    std::string result = sstream.str();
    return result.c_str();
}
