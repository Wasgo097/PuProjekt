#pragma once
extern "C" __declspec(dllexport) void fibonacci_init(unsigned long a, unsigned long b);
extern "C" __declspec(dllexport) bool fibonacci_next();
extern "C" __declspec(dllexport) unsigned long fibonacci_current();
extern "C" __declspec(dllexport) unsigned int fibonacci_index();