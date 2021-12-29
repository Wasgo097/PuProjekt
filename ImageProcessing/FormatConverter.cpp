#include "FormatConverter.h"
#include "PCH.h"
std::string FormatConverter::BinToDec(std::string bin)
{
    /*auto result = std::to_string(std::stoi(bin, 0, 2));;
    return result;*/

  /*  unsigned long long int dec_value = 0;
    unsigned long long int base = 1;
    
    int len = bin.length();
    for (int i = len - 1; i >= 0; i--) {
        if (bin[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    std::string result = std::to_string(dec_value);
    return result;*/
    return std::string();
}
std::string FormatConverter::BinToHex(std::string bin)
{
    /*std::stringstream res;
    const auto length = bin.length();
    std::bitset<length> set(bin);
    res << std::hex << std::uppercase << set.to_ulong();
    return res.str();*/
    return std::string();
}