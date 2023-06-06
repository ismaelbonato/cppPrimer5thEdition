#include <iterator>
#include <ostream>
#include <string>
#include <iostream>
#include <vector>

int main()
{
    int i = 0;
    std::vector<int> iVector;

    while (std::cin >> i) {
        iVector.push_back(i);
    }

    for (auto d : iVector) {
        std::cout << d << " ";
    }

    return 0;
}