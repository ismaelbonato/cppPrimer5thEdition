#include <iterator>
#include <ostream>
#include <string>
#include <iostream>

int main()
{
    std::string str("Hello World!!!");
    int counter = 0;

    for (auto &idx: str) {
        idx = 'X';
    }
    std::cout << str << std::endl;

    return 0;
}