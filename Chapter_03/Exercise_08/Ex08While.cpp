#include <iterator>
#include <ostream>
#include <string>
#include <iostream>

int main()
{
    std::string str("Hello World!!!");
    decltype(str.size()) counter = 0;

    while (counter < str.size()) {
        str[counter] = 'X';
        counter++;
    }

    std::cout << str << std::endl;

    return 0;
}