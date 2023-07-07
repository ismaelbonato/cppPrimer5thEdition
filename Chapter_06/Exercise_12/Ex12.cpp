#include <iostream>

void swap(int &xValue, int &yValue)
{
    int tmp = xValue;

    xValue = yValue;
    yValue = tmp;
}

int main()
{
    int x = 42, y = 1;

    std::cout << "x, y = " << x << ", " << y << std::endl;

    swap(x, y);

    std::cout << "the result of swapped: " << x << ", " << y << std::endl;
    
    return 0;
}