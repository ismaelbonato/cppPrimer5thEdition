#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};

int main()
{
    std::string line, word;
    std::vector<PersonInfo> people;
    std::istringstream record; 

    while (getline(std::cin, line)) {
        PersonInfo info; 
        record.clear();
        record.str(line);

        record >> info.name; 

        while (record >> word) {
            info.phones.push_back(word); 
        }
        people.push_back(info); 
    }

    for (const auto &person:people) {
        std::cout << person.name << " ";
        for (auto number : person.phones) {
            std::cout << number << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}