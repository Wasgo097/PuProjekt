#include <iostream>
#include <string>
#include "ProjectAPI.h"
int main()
{
	for (int i = 1; i <= 6; i++) {
		std::string path = "C:\\programowanie\\proj PO\\PuProjekt\\examples\\"+std::to_string(i)+".jpg";
		char result[255];
		GetCodeFromImg(path.c_str(), 0, result);
		std::cout << "------\nRESULT: " << result<<std::endl;
	}
	return 0;
}