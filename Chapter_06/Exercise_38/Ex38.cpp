#include <iostream>

const int odd[] = {1,3,5,7,9};
const int even[] = {0,2,4,6,8};
// returns a reference to an array of five int elements
decltype(odd) &arrPtr(int i)
{
    return (i % 2) ? odd : even; // returns  pointer to the array
}

int main ()
{
    std::cout << "arrPtr(1): ";

    for (auto number : arrPtr(1)) {
        std::cout << number << ' ';
    }

    std::cout << std::endl << "arrPtr(2): ";

    for (auto number : arrPtr(2)) {
        std::cout << number << ' ';
    }
    std::cout << std::endl;

    return 0;
}