#include <cstddef>
#include <iterator>
#include <ostream>
#include <string>
#include <iostream>
#include <vector>

#include <cstring>

int main()
{   
    std::vector<int> iVec{0, 1, 2, 3, 4, 5, 6};
    int iArr[7] = {0, 0, 0, 0, 0, 0, 0};

    auto *pbiArr = std::begin(iArr);

    for (auto i : iVec) {
        *pbiArr++ = i;
    }

    for (auto i : iArr ) {
        std::cout << i;
    }

    std::cout << std::endl;

    return 0;
}