#include "FormatConverter.h"
#include "PCH.h"
std::string FormatConverter::BinToDec(std::string bin)
{
    return std::to_string(std::stoi(bin,0,2));
}
std::string FormatConverter::BinToHex(std::string bin)
{
    std::stringstream res;
    std::bitset<8> set(bin);
    res << std::hex << std::uppercase << set.to_ulong();
    return res.str();
}