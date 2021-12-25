#include "ProjectAPI.h"

void InitApi()
{
	ApiInitialized = true;
}

char* GetCodeFromImg(char* ImagePath)
{
	if (ApiInitialized == false)
		InitApi();
	return nullptr;
}
