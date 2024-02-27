#include <iostream>

class x;
class y;

class x {
    y *pY;
};

class y {
    x X;
};

int main(void)
{
    return 0;
}