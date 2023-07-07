#include <iostream>
#include <iterator>
#include <stdexcept>

unsigned long long fac(int value) 
{
    if (value < 0) {
        throw std::runtime_error{"The input number cannot be negative"};
    }

    unsigned long long res = 1;

    while (value > 1) {
        res *= value--;
    }

    return res;
}

int facGen (void) 
{
    int num = 0;
    long long factorial;

    std::cout << "Digit a number: "; 
    std::cin >> num;
    
    try {
        factorial = fac(num);
    } catch (std::runtime_error) {
        std::cout << "Error: The input number cannot be negative" << std::endl;
        return -1;
    }

    std::cout << std::endl 
            << "The factorial of " << num << " is: " 
            << factorial << std::endl;
    return 0;
}

int main () 
{
    return facGen();
}