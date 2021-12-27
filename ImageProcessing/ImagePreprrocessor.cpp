#include "ImagePreprocessor.h"
#include "PCH.h"
#include "DebugDrawing.h"
#define ADVANCED
ImagePreprocessor::ImagePreprocessor(cv::Mat InMat, PreprocessingSettings settings):_inputmat(InMat),_inputsettings(std::move(settings))
{}

cv::Mat ImagePreprocessor::GetPreprocessedImage() const
{
	cv::Mat result,gausian,canny;
	cv::Mat inputcopy = _inputmat.clone();
	cv::cvtColor(inputcopy, inputcopy, cv::COLOR_BGR2GRAY);
#ifdef ADVANCED
		cv::GaussianBlur(inputcopy, gausian, cv::Size(_inputsettings._gausiankernelsize, _inputsettings._gausiankernelsize), 3);
		cv::Canny(gausian, canny, _inputsettings._cannytreshold1, _inputsettings._cannytreshold2);
		cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(_inputsettings._morphologykernelsize, _inputsettings._morphologykernelsize));
		cv::erode(canny, result, kernel);
	#ifdef PREPROCESSING_DRAW
		cv::imshow("imggaus", gausian);
		cv::imshow("imgcanny", canny);
		cv::imshow("imgres", result);
		cv::waitKey(0);
	#endif
#else
	result = inputcopy;
#endif
	return result;
}
