#include <iterator>
#include <map>
#include <ostream>
#include <string>
#include <iostream>
#include <cctype>
#include <utility>
#include <algorithm>

int main ()
{
    std::multimap<std::string, std::string> authors{
                    {"Frank Herbert", "Dune"},
                    {"Frank Herbert", "Dune Messiah"},
                    {"Frank Herbert", "Children of Dune"},
                    {"Frank Herbert", "God Emperor of Dune"},
                    {"Frank Herbert", "Heretics of Dune"},
                    {"Orson Scott Card", "Ender's Game"},
                    {"Orson Scott Card", "Speaker for the Dead"},
                    {"Orson Scott Card", "Xenocide"},
                    {"Orson Scott Card", "Children of the Mind"},
                    {"Orson Scott Card", "Ender's Shadow	"},
                    {"Orson Scott Card", "Shadow of the Hegemon"},
                    {"Orson Scott Card", "First Meetings in Ender's Universe"}
                    };

    std::string auth("Orson Scott Card");
    std::string bookToExclude("Xenocide");

    for (auto pos = authors.equal_range(auth); 
                                            pos.first != pos.second; 
                                            ++pos.first)  {
        if (pos.first->second == bookToExclude) {
            std::cout << bookToExclude << " book found, deleting" << std::endl;    
            pos.first = authors.erase(pos.first); 
            break;
        }
    }

    for (auto author : authors) {
        std::cout << "Author: " << author.first << " Book: " << author.second 
            << std::endl;
    }

    return  0;
}