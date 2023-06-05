#include <iterator>
#include <ostream>
#include <string>
#include <iostream>

int main()
{
    std::string stringA;
    std::string stringB;

    std::cin >> stringA >> stringB; 

    if (stringA.size() == stringB.size()) {
        std::cout << "stringA has the same size than stringB" << std::endl;
    } else {
    
        if (stringA.size() > stringB.size()) {
                std::cout << "stringA is larger than stringB" << std::endl;
        } else {
                std::cout << "stringB is larger than stringA" << std::endl;
        }
    }
    
    return 0;
}