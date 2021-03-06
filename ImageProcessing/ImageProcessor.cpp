#include "ImageProcessor.h"
#include "PCH.h"
#include "DebugDrawing.h"
ImageProcessor::ImageProcessor(cv::Mat PreprocessedImage, cv::Mat OriginalImage, ProcessingSettings settings):_preprocessedimage(PreprocessedImage),_originalimage(OriginalImage),_inputsettings(std::move(settings))
{}
cv::Mat ImageProcessor::GetProcessedImage() const
{
	cv::Mat result = _originalimage.clone();
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	cv::findContours(_preprocessedimage, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	int lowest_contour_index = -1;
	int lowest_contour_y = -1;
	for (int i = 0; i < contours.size();i++) {
		auto& contour = contours[i];
		auto rect=cv::boundingRect(contour);
		if (rect.y > lowest_contour_y) {
			lowest_contour_y = rect.y;
			lowest_contour_index = i;
		}
	}
	std::vector<cv::Point> allpoints;
	for (int i = 0; i < contours.size(); i++) {
		if (i == lowest_contour_index)
			continue;
		for (const auto& point : contours[i])
			allpoints.push_back(point);
/*#ifdef  PROCESSING_DRAW
		cv::drawContours(result, contours, i, cv::Scalar(255, 0, 255), 1);
#endif*/ 
	}
	auto finalroi = cv::boundingRect(allpoints);
	result = result(finalroi);
#ifdef  PROCESSING_DRAW
	cv::resize(result, result, cv::Size(), 3.0, 3.0);
	cv::imshow("processingimg", result);
	cv::waitKey(0);
#endif 
	cv::cvtColor(result, result, cv::COLOR_BGR2GRAY);
	return result;
}
