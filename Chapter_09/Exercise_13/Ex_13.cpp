#include <vector>
#include <list>
#include <iostream>


int main()
{
    std::list<int> iList{0, 1, 2, 3, 4, 5};
    std::vector<int> iVec{0, 1, 2, 3, 4, 5};

    std::vector<double> dVec1(iVec.begin(), iVec.end());
    std::vector<double> dVec2(iList.begin(), iList.end());

    for (const auto &number : dVec1) {
        std::cout << number << std::endl;
    }

    for (const auto &number : dVec2) {
        std::cout << number << std::endl;
    }

    return 0;
}

