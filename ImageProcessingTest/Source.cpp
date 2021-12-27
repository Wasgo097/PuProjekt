#include <iostream>
#include "ProjectAPI.h"
int main()
{
	//std::cout<< GetCodeFromImg("D:\\niemp4\\134391053_856662488402174_3173477362637523884_n.png");
	auto str = GetCodeFromImg("D:\\programowanie\\PuProjekt\\examples\\4.jpg", 0);
	std::cout<< str;
	return 0;
}