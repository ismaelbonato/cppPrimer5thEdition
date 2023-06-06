#include <iterator>
#include <ostream>
#include <string>
#include <iostream>
#include <vector>

int main()
{
    int i;
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
    
    for (decltype(iVector.size()) idx = 0; idx < ((iVector.size()+1)/2); idx++) {    
        std::cout << iVector[idx] + iVector[(iVector.size() - 1) -idx] << " ";
    }
    
    return 0;
}