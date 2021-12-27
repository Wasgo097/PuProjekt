#pragma once
static bool ApiInitialized = false;
extern "C" __declspec(dllexport) void InitApi();
extern "C" __declspec(dllexport) const char* GetCodeFromImg(const char * ImagePath);