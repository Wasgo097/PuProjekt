#include "ProjectAPI.h"
#include "ImageSource.h"
void InitApi()
{
	ApiInitialized = true;
}

const char* GetCodeFromImg(const char* ImagePath)
{
	if (ApiInitialized == false)
		InitApi();
	ImageSource source;
	auto img = source.GetImage(ImagePath);
	if (img) {
		cv::Mat& baseimage = *img;

		return "result";
	}
	else {
		return "null";
	}
}
