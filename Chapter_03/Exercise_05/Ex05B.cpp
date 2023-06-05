#include <iterator>
#include <ostream>
#include <string>
#include <iostream>

int main()
{
    std::string str, strTmp;

    while (std::cin >> str) {
       strTmp += (str + " ");
    }
    
    std::cout << strTmp << std::endl; 

    return 0;
}