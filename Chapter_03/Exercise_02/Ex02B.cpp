#include <ostream>
#include <string>
#include <iostream>

// run
// a.out < input
int main()
{
    std::string line, word;

    while (std::cin >> word) {
        std::cout << word << std::endl;
    }

    return 0;
}