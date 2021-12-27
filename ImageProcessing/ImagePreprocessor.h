#pragma once
#include "ProcessingSettings.h"
#include <opencv2/core/mat.hpp>
class ImagePreprocessor
{
public:
	ImagePreprocessor(cv::Mat InMat, PreprocessingSettings settings);
	cv::Mat GetPreprocessedImage()const;
private:
	cv::Mat _inputmat;
	PreprocessingSettings _inputsettings;
};

