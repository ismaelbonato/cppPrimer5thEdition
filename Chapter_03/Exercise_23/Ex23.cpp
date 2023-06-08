#include <cctype>
#include <iterator>
#include <ostream>
#include <string>
#include <iostream>
#include <vector>

int main()
{
    std::string line;
    std::vector<int> iVector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    std::cout << "Vector: ";

    for (auto ival : iVector) {
        std::cout << ival << ", ";
    }


    for (auto it = iVector.begin(); it != iVector.end(); it++) {
        *it *= 2;
    }

    std::cout << std::endl << "Result: ";

    for (auto ival : iVector) {
        std::cout << ival << ", ";
    }

    return 0;
}