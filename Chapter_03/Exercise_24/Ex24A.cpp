#include <iterator>
#include <ostream>
#include <string>
#include <iostream>
#include <vector>

int main()
{
    int i, tmp = 0;

    std::vector<int> iVector;

    while (std::cin >> i) {
        iVector.push_back(i);
    }

    std::cout << std::endl << "Numbers:" << " ";

    for (auto i : iVector) {
        std::cout << i << " ";
    }

    if (iVector.size() <= 1) {
        std::cout << "One value has not adjacent number" << std::endl;
        return 1;
    }

    std::cout << std::endl << "The Sum: ";

    for (auto it = iVector.begin(); it != (iVector.end() -1); it++) {
        std::cout << *it + *(it + 1) << " ";        
    }
    
    return 0;
}