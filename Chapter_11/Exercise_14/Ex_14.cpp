#include <map>
#include <string>
#include <iostream>
#include <cctype>
#include <utility>
#include <vector>

int main ()
{
    using childData = std::pair<std::string, std::string>;
    using names = std::vector<childData>;

    std::string family, child, birthday;
     
    std::map<std::string, names> agenda;

    std::cout << "ctrl + d to print" << std::endl;
    std::cout << "enter family name" << std::endl;

    while (std::getline(std::cin, family)) {
    
        std::cout << "Enter child name" << std::endl;
        std::getline(std::cin, child);

        std::cout << "Enter child birthday year year/month/day" << std::endl;
        std::getline(std::cin, birthday);

        agenda[family].emplace_back(child, birthday);

        std::cout << "ctrl + d to print" << std::endl;
        std::cout << "enter family name" << std::endl;
    }

    std::cout << std::endl;
    for (auto &family : agenda)
    {
        std::cout << "Family Name: " << family.first << std::endl << "Childrens: ";
        for (auto &name : family.second) {
             std::cout << name.first << " " << name.second  << std::endl;
        }
        std::cout << std::endl;

    }

    return  0;
}