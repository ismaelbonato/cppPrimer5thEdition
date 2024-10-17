#include <map>
#include <string>
#include <iostream>
#include <cctype>
#include <vector>

int main ()
{
    using names = std::vector<std::string>;

    std::string family, child;
    
    std::map<std::string, names> agenda;

    std::cout << "ctrl + d to print" << std::endl;
    std::cout << "enter family name" << std::endl;

    while (std::getline(std::cin, family)) {
    
        std::cout << "Enter child name" << std::endl;
        std::getline(std::cin, child);

        agenda[family].push_back(child);

        std::cout << "ctrl + d to print" << std::endl;
        std::cout << "enter family name" << std::endl;
    }

    for (auto &family : agenda)
    {
        std::cout << "Family Name: " << family.first << std::endl << "Childrens: ";
        for (auto &name : family.second) {
             std::cout << name << ", ";
        }
        std::cout << std::endl;

    }

    return  0;
}