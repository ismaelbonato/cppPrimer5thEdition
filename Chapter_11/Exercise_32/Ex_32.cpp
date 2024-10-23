#include <iterator>
#include <map>
#include <ostream>
#include <set>
#include <string>
#include <iostream>
#include <cctype>
#include <utility>
#include <algorithm>

int main ()
{
    std::multimap<std::string, std::string> authors{
                    {"Orson Scott Card", "Ender's Game"},
                    {"Orson Scott Card", "Speaker for the Dead"},
                    {"Orson Scott Card", "Xenocide"},
                    {"Orson Scott Card", "Children of the Mind"},
                    {"Orson Scott Card", "Ender's Shadow	"},
                    {"Orson Scott Card", "Shadow of the Hegemon"},
                    {"Orson Scott Card", "First Meetings in Ender's Universe"},
                    {"Frank Herbert", "Dune"},
                    {"Frank Herbert", "Dune Messiah"},
                    {"Frank Herbert", "Children of Dune"},
                    {"Frank Herbert", "God Emperor of Dune"},
                    {"Frank Herbert", "Heretics of Dune"}
                    };

    std::map<std::string, std::multiset<std::string>> orderedBooks;

    auto beg = authors.begin();

    while (beg != authors.end()) {
        auto authorRange = authors.equal_range(beg->first);        
        for (auto pos = authorRange;
                                        pos.first != pos.second; ++pos.first) {
            orderedBooks[beg->first].insert(pos.first->second);
        }
        beg = authorRange.second;
    }
    
    for (auto &auth : orderedBooks) {
        for (auto book : auth.second) {
            std::cout << "Author: " << auth.first << " Book: " << book 
            << std::endl;
        }
    }

    return  0;
}