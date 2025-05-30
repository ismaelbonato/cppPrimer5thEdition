#include <iostream>
#include "Screen.h"
#include <sstream>

int main()
{
    Screen<5,5> screen('H');

    std::cout << "Screen size = " << screen.size() << std::endl;

    std::stringstream ss("XXXX");

    ss >> screen;

    std::cout << screen << std::endl;

    return 0;
}