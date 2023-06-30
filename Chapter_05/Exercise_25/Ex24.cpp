#include <iostream>
#include <stdexcept>

int main ()
{
    int x = 0, y = 0, r = 0;

    while (std::cout << "Please, insert two numbers or ctrl + c to exit: "
            ,std::cin >> x >> y) {
        try {
            if ( y == 0 ) {
                throw std::invalid_argument("divided by zero.");
            } else {
                r = x/y;
                std::cout << "Result: " << r << std::endl;
            }
        } catch (std::invalid_argument) {
            std::cout << "The second number cannot be zero, please supply new numbers:" << std::endl;
        }
    }

    return 0;
}