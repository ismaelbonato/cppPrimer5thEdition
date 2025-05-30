#include "Blob.h"
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> sVec{"Hello ", "World", "!"};
    Blob<std::string> b(sVec.begin(), sVec.end());

    for (auto it = b.begin(); it != b.end(); it++) {
        std::cout << *it << std::endl;
    }

    Blob<int> x{1,2,3,4,5,6,7,8,9};


    for (auto it = x.begin(); it != x.end(); it++) {
        std::cout << *it << std::endl;
    }


    return 0;
}