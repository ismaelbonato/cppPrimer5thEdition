#include <iterator>
#include <ostream>
#include <string>
#include <iostream>
#include <cctype>

int main()
{
    std::string str;

    std::getline(std::cin, str);

    for (auto c : str) {
        if (!std::ispunct(c)) {
            std::cout << c;
        }
    }

    return 0;
}