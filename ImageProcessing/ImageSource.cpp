#include "ImageSource.h"
std::optional<cv::Mat> ImageSource::GetImage(const char* path)
{
	cv::Mat result = cv::imread(path);
//	cv::cvtColor(result, result, cv::ColorConversionCodes::COLOR_BGR2GRAY);
	if (result.empty())
		return {};
	else {
		cv::imshow("img", result);
		cv::waitKey(0);
		return result;
	}
}
