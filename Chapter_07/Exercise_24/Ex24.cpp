#include <iostream>
#include "Screen.h"

int main()
{
    Screen screen(10, 5, 'u');

    std::cout << "The character on position 4,4 is "<< screen.moveCursor(4,4).get() << std::endl;

    return 0;
}
