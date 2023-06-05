#include <ostream>
#include <string>
#include <iostream>

// run
// a.out < input
int main()
{
    std::string line, word;

    while (std::getline(std::cin, line)) {
        std::cout << line << std::endl;
    }

    return 0;
}