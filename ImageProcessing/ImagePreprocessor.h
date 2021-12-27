#pragma once
#include "ProcessingSettings.h"
#include <opencv2/core/mat.hpp>
class ImagePreprocessor
{
public:
	ImagePreprocessor(cv::Mat InMat, ProcessingSettings settings);
	cv::Mat GetPreprocessedImage()const;
private:
	cv::Mat _inputmat;
	ProcessingSettings _inputsettings;
};

