#include <iterator>
#include <ostream>
#include <string>
#include <iostream>

int main()
{
    std::string str("Hello World!!!");
    decltype(str.size()) counter = 0;

    for (counter =0; counter < str.size(); counter++) {
        str[counter] = 'X';
    }

    std::cout << str << std::endl;

    return 0;
}