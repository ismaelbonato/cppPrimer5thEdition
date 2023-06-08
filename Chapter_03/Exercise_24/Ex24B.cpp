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

    int v[40];
    for (auto &x : v) {
        x = 3;
    }

    std::cout << std::endl << "The Sum with one iterator: ";

    for (auto it = iVector.begin(); 
        it != (iVector.end() - ((iVector.size())/2) ); 
        it++) {    
        std::cout << *it + *(iVector.begin() - (it - iVector.end()) -1)  << " ";
    }

    std::cout << std::endl << "The Sum with two iterator ";

    auto mid = (iVector.end() - ((iVector.size())/2) );
    auto end = iVector.end() - 1;

    for (auto it = iVector.begin(); it != mid; 
        it++) {    
        std::cout << *it + *(end--)  << " ";
    }

    return 0;
}