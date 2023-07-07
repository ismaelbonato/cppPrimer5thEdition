#include <iostream>

long long absoluteValue(const long long value)
{
    return value < 0 ? -value : value;
}

int main(void)
{

    long long num = 0;

    std::cout << "Digit a number: "; 
    std::cin >> num;
    
    std::cout << std::endl 
            << "The factorial of " << num << " is: " 
            << absoluteValue(num) << std::endl;

    return 0;
}