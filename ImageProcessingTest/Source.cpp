#include <iostream>
#include <string>
#include "ProjectAPI.h"
int main()
{
	//std::cout<< GetCodeFromImg("D:\\niemp4\\134391053_856662488402174_3173477362637523884_n.png");
	for (int i = 1; i <= 6; i++) {
		std::string path = "D:\\programowanie\\PuProjekt\\examples\\"+std::to_string(i)+".jpg";
		char result[255];
		GetCodeFromImg(path.c_str(), 0, result);
		std::cout << "------\nRESULT: " << result<<std::endl;
	}
	return 0;
}