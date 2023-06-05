#include <iterator>
#include <ostream>
#include <string>
#include <iostream>

int main()
{
    std::string stringA;
    std::string stringB;

    std::cin >> stringA >> stringB; 

    if (stringA == stringB) {
        std::cout << "stringA is equal to stringB" << std::endl;
    } else {

        if (stringA > stringB) {
            std::cout << "stringA is greater than stringB" << std::endl;
        } else {
            std::cout << "stringA is less than stringB" << std::endl;
        }
    } 

    return 0;
}