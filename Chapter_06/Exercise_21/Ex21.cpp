#include <iostream>
#include <string>


int theLarger(const int x, const int *y)
{
    return (x > *y ? x : *y);
}

int main ()
{
    const int x = 10;
    const int y = 15;
    const int *py = &y;

    std::cout << theLarger(x, py) << std::endl;

    return 0;
}
