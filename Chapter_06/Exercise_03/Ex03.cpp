#include <iostream>
#include <iterator>

int main () 
{
    unsigned long long num = 0;
    unsigned long long res, x;

    while (res = 1, std::cout << "Digit a number: ", std::cin >> num) {
        std::cout << std::endl 
                    << "The factorial of " << num << " is: " ;

        while (num > 1) {
            res *= num--;
        }
        
        std::cout << res << std::endl;
    }

    return 0;
}