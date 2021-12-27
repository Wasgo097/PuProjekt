#pragma once
#include <opencv2/imgcodecs.hpp>
#include <optional>
class ImageSource
{
public:
	std::optional<cv::Mat> GetImage(const char * path);
};