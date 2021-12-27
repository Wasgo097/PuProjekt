#include "ImageSource.h"
#include "PCH.h"
std::optional<cv::Mat> ImageSource::GetImage(const char* path)
{
	cv::Mat result = cv::imread(path);
	cv::cvtColor(result, result, cv::ColorConversionCodes::COLOR_BGR2GRAY);
	if (result.empty())
		return {};
	else {
		cv::resize(result, result, cv::Size(), 3.0, 3.0);
		cv::imshow("img", result);
		return result;
	}
}
