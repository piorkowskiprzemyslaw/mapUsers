#include "Helper.h"

Helper::Helper()
{
    //ctor
}

Helper::~Helper()
{
    //dtor
}

std::pair<unsigned char, unsigned char> Helper::TBCDByteEncode(unsigned char byte)
{
    unsigned char first = byte & 0x0f;
    unsigned char second = byte & 0xf0;
    second = second >> 4;
    return std::make_pair(first, second);
}
