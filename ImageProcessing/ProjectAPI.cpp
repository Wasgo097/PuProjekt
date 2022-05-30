#include "ProjectAPI.h"
#include "ImageSource.h"
#include "ImagePreprocessor.h"
#include "ImageProcessor.h"
#include "ImageConverter.h"
#include "PCH.h"
#include "DebugDrawing.h"
#pragma warning(disable : 4996)
void GetCodeFromImg(const char* ImagePath,int codetype, char* Result)
{
	ImageSource source;
	auto original_img = source.GetImage(ImagePath);
	if (original_img) {
		ImagePreprocessor preprocessor(*original_img, PreprocessingSettings());
		auto preprocessing_res = preprocessor.GetPreprocessedImage();
		if (!preprocessing_res.empty()) 
		{
			ImageProcessor processor(preprocessing_res,*original_img, ProcessingSettings());
			auto processing_res = processor.GetProcessedImage();
#ifdef  FINAL_DRAW
			//cv::resize(processing_res, processing_res, cv::Size(), 6.0, 6.0);
			cv::imshow("final img", processing_res);
			cv::waitKey(0);
#endif 
			ImageConverter converter;
			std::string result = converter.ConvertImageToCode(processing_res);
			strcpy(Result, result.c_str());
		}
	}
}
