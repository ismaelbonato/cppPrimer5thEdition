#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main ()
{
    std::vector<int> iVec{1,2,3,4,5,6};

    for (auto number : iVec) {
        std::cout << number << ", ";
    }
    std::cout << std::endl;

    std::fill_n(iVec.begin(), iVec.size(), 0);

    for (auto number : iVec) {
        std::cout << number << ", ";
    }
    std::cout << std::endl;

}