#include <iostream>
#include <list>
#include <string>
#include <deque>

int main()
{
    std::deque<int> odd, even;
    std::list<int> numbers{1,2,3,4,5,6,7,8,9,10,11,12,13};

    for (const auto &number : numbers) {
        if (number % 2) {
            even.push_back(number);
        } else {
            odd.push_back(number);
        }
    }

    std::cout << "Even Numbers: ";

    for (const auto &number : even) {
        std::cout << number << ", ";
    }

    std::cout << std::endl << "Odd Numbers: ";

    for (auto begin = odd.begin(); begin != odd.end(); ++begin) {
        std::cout << *begin << ", ";
    }

    std::cout << std::endl;

    return 0;
}