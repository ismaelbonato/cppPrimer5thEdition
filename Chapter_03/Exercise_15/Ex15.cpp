#include <iterator>
#include <ostream>
#include <string>
#include <iostream>
#include <vector>

int main()
{
    std::string str;
    std::vector<std::string> sVector;

    while (std::cin >> str) {
        sVector.push_back(str);
    }

    for (auto s : sVector) {
        std::cout << s << " ";
    }

    return 0;
}