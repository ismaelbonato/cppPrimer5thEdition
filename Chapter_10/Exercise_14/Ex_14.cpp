#include <iostream>

int main()
{
    int a = 5;
    int b = 2;

    auto sum = [] (const int a, const int b) {
        return a + b;
    };

    std::cout << "the sum of " << a << " + " << b << " is: " 
    << sum(a,b) << std::endl;

    return 0;
}