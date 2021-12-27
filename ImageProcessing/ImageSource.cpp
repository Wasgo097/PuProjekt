#include "ImageSource.h"
#include "PCH.h"
#include "DebugDrawing.h"
std::optional<cv::Mat> ImageSource::GetImage(const char* path)const {
	cv::Mat result = cv::imread(path);
	if (result.empty())
		return {};
	else {
#ifdef SOURCE_DRAW
		cv::resize(result, result, cv::Size(), 3.0, 3.0);
		cv::imshow("img", result);
		cv::waitKey(0);
#endif
		return result;
	}
}
