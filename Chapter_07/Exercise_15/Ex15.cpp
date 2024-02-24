#include <iostream>
#include <string>
#include "Person.h"


int main() 
{
    Person jhon = std::cin;
    
    print(std::cout, jhon) << std::endl;

    Person maria{"Maria", "Rua da amargura"};
    print(std::cout, maria) << std::endl;

    return 0;
}