#include <iostream>


void reset(int &value)
{
    value = 0;
}

int main()
{
    int x = 42;

    std::cout << "First value of x before the reset(): " << x << std::endl;
    reset(x);
    std::cout << "The value of x after the reset(): " << x << std::endl;

    return 0;
}