#pragma once
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <optional>
class ImageSource
{
public:
	std::optional<cv::Mat> GetImage(const char * path);
};