#include <iostream>
#include <stdexcept>

int main ()
{
    int x = 0, y = 0, r = 0;

    std::cin >> x >> y;

    if ( y == 0 ) {
        throw std::invalid_argument("Dvision by zero.");
    } else {
        r = x/y;
        std::cout << "Result: " << r << std::endl;
    }

    return 0;
}