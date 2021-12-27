#pragma once
#include <opencv2/core/mat.hpp>
#include <optional>
class ImageSource
{
public:
	std::optional<cv::Mat> GetImage(const char * path)const;
};