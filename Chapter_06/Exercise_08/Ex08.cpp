#include <iostream>
#include <iterator>
#include <stdexcept>

#include "Chapter6.h"

int main () 
{
    return facGen();
}

unsigned long long fac(int value) 
{
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
    
   
    factorial = fac(absoluteValue(num));
   
    std::cout << std::endl 
            << "The factorial of " << num << " is: " 
            << factorial << std::endl;

    return 0;
}

long long absoluteValue(const long long value)
{
    return value < 0 ? -value : value;
}