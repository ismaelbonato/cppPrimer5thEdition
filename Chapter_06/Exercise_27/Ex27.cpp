#include <iostream>
#include <initializer_list>

const long sumOfElements(const std::initializer_list<const int> &pNumbers)
{
    long sum = 0;
    for (const auto &pNumber: pNumbers) {
        sum += pNumber;
    }

    return sum;
}

int main()
{
    std::cout << "The sum of elements is: " 
        << sumOfElements({1,
                                    2,
                                    3,
                                    4,
                                    5})
        << std::endl;

    return 0;
}
