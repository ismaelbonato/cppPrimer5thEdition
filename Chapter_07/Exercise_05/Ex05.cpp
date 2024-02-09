#include <iostream>
#include <string>
#include "Person.h"


int main() 
{
    const Person jhon = {"Jhon", "boulevard broken dreams"};

    std::cout << "Name: " << jhon.getName() << std::endl
              << "Address: "  << jhon.getAddress() << std::endl;

    return 0;
}