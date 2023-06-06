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

    std::cout << "Words:" << std::endl;

    for (auto s : sVector) {
        std::cout << s << " ";
    }

    std::cout << std::endl << "Uppercase Words:" << std::endl;

    for (auto &v : sVector) {
        for ( auto &s : v) {
            s = std::toupper(s);
        }
    }
    
    for (auto s : sVector) {
        std::cout << s << " ";
    }
    



    return 0;
}