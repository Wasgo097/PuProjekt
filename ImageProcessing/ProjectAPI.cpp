#include "ProjectAPI.h"
#include "ImageSource.h"
#include "ImagePreprocessor.h"
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
		ImagePreprocessor preprocessor(*img, ProcessingSettings());
		auto res = preprocessor.GetPreprocessedImage();
		return "result";
	}
	else {
		return "null";
	}
}
