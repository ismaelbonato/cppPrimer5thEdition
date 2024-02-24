#include <iostream>
#include "Screen.h"

int main()
{
    Screen screen(10, 5, 'u');
    

    std::cout << "The character on position 4,4 is "<< screen.moveCursor(4,4).get() << std::endl;

    Screen screenCpy = screen;

    std::cout << "the cursor position is getCursorPos is "  
        << screenCpy.getCursorPos()
        << " The character on position is "
        << screenCpy.moveCursor(4,4).get() << std::endl;

    Screen screenAssign;

    screenAssign = screenCpy;

        std::cout << "the cursor position is getCursorPos is "  
        << screenAssign.getCursorPos()
        << " The character on position is "
        << screenAssign.moveCursor(4,4).get() << std::endl;

    return 0;
}
