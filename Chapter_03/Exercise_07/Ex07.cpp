#include <iterator>
#include <ostream>
#include <string>
#include <iostream>

int main()
{
    std::string str("Hello World!!!");

    for (char &idx: str) {
        idx = 'A';
    }
    std::cout << str << std::endl;

    return 0;
}