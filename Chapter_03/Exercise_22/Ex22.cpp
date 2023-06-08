#include <cctype>
#include <iterator>
#include <ostream>
#include <string>
#include <iostream>
#include <vector>

int main()
{
    std::string line;
    std::vector<std::string> sVector;
    
    while (std::getline(std::cin, line)) {
        sVector.push_back(line);
    }

    std::cout << std::endl << "Result:" << std::endl;
   

    // more readable
    for (auto &str : sVector) {
        auto ch = str.begin();
        *ch = std::toupper(*ch);
    }

    for (auto s : sVector) {
        std::cout << s << std::endl;
    }
    
    return 0;
}