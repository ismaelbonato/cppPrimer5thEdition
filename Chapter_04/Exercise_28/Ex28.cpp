#include <iostream>

int main()
{
    std::cout <<"char size in Bytes:" << sizeof(char) << std::endl;
    std::cout <<"wide char size in Bytes:" << sizeof(wchar_t) << std::endl;
    std::cout <<"short size in Bytes:" << sizeof(short) << std::endl;
    std::cout <<"int size in Bytes:" << sizeof(int) << std::endl;
    std::cout <<"long size in Bytes:" << sizeof(long) << std::endl;
    std::cout <<"long long size in Bytes:" << sizeof(long long) << std::endl;
    std::cout <<"float size in Bytes:" << sizeof(float) << std::endl;
    std::cout <<"double size in Bytes:" << sizeof(double) << std::endl;
    std::cout <<"long double size in Bytes:" << sizeof(long double) << std::endl;

    return 0;
}