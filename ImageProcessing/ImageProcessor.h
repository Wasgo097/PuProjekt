#pragma once
#include "ProcessingSettings.h"
#include <opencv2/core/mat.hpp>
class ImageProcessor
{
public:
	ImageProcessor(cv::Mat PreprocessedImage,cv::Mat OriginalImage,ProcessingSettings settings);
	cv::Mat GetProcessedImage()const;
private:
	cv::Mat _originalimage;
	cv::Mat _preprocessedimage;
	ProcessingSettings _inputsettings;
};

