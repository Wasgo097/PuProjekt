#include "ImagePreprocessor.h"
#include "PCH.h"

ImagePreprocessor::ImagePreprocessor(cv::Mat InMat, ProcessingSettings settings):_inputmat(InMat),_inputsettings(std::move(settings))
{
}

cv::Mat ImagePreprocessor::GetPreprocessedImage() const
{
	cv::Mat result,gausian,canny;
	cv::GaussianBlur(_inputmat, gausian, cv::Size(_inputsettings._gausiankernelsize, _inputsettings._gausiankernelsize), 3);
	cv::imshow("imggaus", gausian);
	cv::Canny(gausian, canny, _inputsettings._cannytreshold1, _inputsettings._cannytreshold2);
	cv::imshow("imgcanny", canny);
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(_inputsettings._morphologykernelsize, _inputsettings._morphologykernelsize));
	cv::erode(canny, result, kernel);
	cv::resize(result, result, cv::Size(), 3.0, 3.0);
	cv::imshow("imgres", result);
	cv::waitKey(0);
	return result;
}
