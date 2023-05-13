#include <iostream>

int main()
{
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i) {
        sum += i;
    }
    // i = 100 and sum is 9! factorial = 45
    std::cout << i << " " << sum << std::endl;
}
