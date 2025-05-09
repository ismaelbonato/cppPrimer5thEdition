#include "StrVec.h"
#include <vector>

int main()
{         
    StrVec a1;
    a1.push_back("Hello");
    a1.push_back("World");

    StrVec a2;
    a2 = {"Hello", "World"};

    std::cout << "a1 < a2 = " << (a1 < a2) << std::endl; 
    std::cout << "a1 > a2 = " << (a1 > a2) << std::endl; 
    std::cout << "a1 >= a2 = " << (a1 >= a2) << std::endl; 
    std::cout << "a1 <= a2 = " << (a1 <= a2) << std::endl;

    return 0;
}
