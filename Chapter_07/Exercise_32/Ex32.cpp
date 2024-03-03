#include <iostream>
#include "Screen.h"

int main()
{
    WindowManager windowManager{5, 5, 'X'};

    windowManager.printScreen(0);
    windowManager.clear(0);
    windowManager.printScreen(0);

    return 0;
}
 