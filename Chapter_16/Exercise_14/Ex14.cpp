#include <iostream>
#include "Screen.h"


int main()
{
    Screen<5,5> screen;

    screen.moveCursor(4,0).set('#').display(std::cout);
    std::cout << "\n";
    std::cout << "Screen size = " << screen.size() << std::endl;

    return 0;
}

 