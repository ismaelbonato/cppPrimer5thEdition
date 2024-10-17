#include <map>
#include <string>
#include <iostream>
#include <cctype>
#include <vector>

int main ()
{
    std::string family, child;
    
    std::multimap<std::string, std::string> agenda;

    std::cout << "ctrl + d to print" << std::endl;
    std::cout << "enter family name" << std::endl;

    while (std::getline(std::cin, family)) {
    
        std::cout << "Enter child name" << std::endl;
        std::getline(std::cin, child);

        agenda.insert({family, child});

        std::cout << "ctrl + d to print" << std::endl;
        std::cout << "enter family name" << std::endl;
    }

    std::cout << std::endl;
    for (auto &family : agenda)
    {
        std::cout << "Family Name: " << family.first << std::endl << "Childrens: ";
        std::cout << family.second << " ";

        std::cout << std::endl;
    }

    return  0;
}