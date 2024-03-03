#include <iostream>

class X;
class Y;

class X {
    Y *py;
};

class Y {
    X x;
};

int main(void)
{
    return 0;
}