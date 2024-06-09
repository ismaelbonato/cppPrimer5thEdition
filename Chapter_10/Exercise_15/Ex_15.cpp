

#include <functional>
#include <iostream>

int main ()
{
    int a = 5;
    int b = 3;

    std::function<int(const int)> sum = [a] (const int b) {
        return a + b;
    };

    std::cout << "the sum of " << a << " + " << b << " is: " 
    << sum(b) << std::endl;

    return 0;
}