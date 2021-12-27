#pragma once
#include <opencv2/core/mat.hpp>
#include <string>
class ImageConverter
{
public:
	std::string ConvertImageToCode(cv::Mat InMat)const;
};