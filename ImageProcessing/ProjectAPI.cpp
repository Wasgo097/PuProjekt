#include "ProjectAPI.h"
#include "ImageSource.h"
#include "ImagePreprocessor.h"
#include "ImageProcessor.h"
#include "PCH.h"
void InitApi()
{
	ApiInitialized = true;
}

const char* GetCodeFromImg(const char* ImagePath)
{
	if (ApiInitialized == false)
		InitApi();
	ImageSource source;
	auto original_img = source.GetImage(ImagePath);
	if (original_img) {
		ImagePreprocessor preprocessor(*original_img, PreprocessingSettings());
		auto preprocessing_res = preprocessor.GetPreprocessedImage();
		if (!preprocessing_res.empty()) 
		{
			ImageProcessor processor(preprocessing_res,*original_img, ProcessingSettings());
			auto processing_res = processor.GetProcessedImage();
			return "result";
		}
	}
	return "null";
}
