#include <iostream>
#include <string>
#include "Person.h"


int main() 
{
    Person jhon;
    
    read(std::cin, jhon);

    print(std::cout, jhon);

    return 0;
}