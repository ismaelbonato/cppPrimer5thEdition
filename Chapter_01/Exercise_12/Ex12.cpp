#include <iostream>
int main()
{
    int sum = 0;
    for (int i = -100; i <= 100; ++i)
        sum += i;

    std::cout << "sum is " << sum << std::endl;
    return 0;
}


// the sum of all values between -100 and +100 is 0
