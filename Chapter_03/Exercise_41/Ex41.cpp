#include <cstddef>
#include <iterator>
#include <ostream>
#include <string>
#include <iostream>
#include <vector>

#include <cstring>

int main()
{   
    int iArr[] = {1, 2, 4, 5, 6};

    std::vector<int> iVec(std::begin(iArr), std::end(iArr));

    for (auto ch : iVec) {
        std::cout << ch;
    }

    std::cout << std::endl;

    return 0;
}