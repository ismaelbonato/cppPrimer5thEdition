#include <cstdio>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};

int valid(const std::string &numToValidate) 
{   
    return (numToValidate.length() == 10);
}

std::string format(const std::string &numToFormat)
{
    return "(" + numToFormat.substr(0, 3) +
            ") " + numToFormat.substr(3, 3) +
            "-"  + numToFormat.substr(6, 4) + 
            " ";
}

int main()
{
    std::string line, word;
    std::vector<PersonInfo> people;
    std::istringstream record; 

    std::ifstream file("input");
    
    if (!file) {
        std::cerr << "File not found " << std::endl;
        return -1;
    }

    while (getline(file, line)) {
        PersonInfo info; 
        record.clear();
        record.str(line);

        record >> info.name; 

        while (record >> word) {
            info.phones.push_back(word); 
        }
        people.push_back(info); 
    }

    for (const auto &entry : people) { 
        std::ostringstream formatted, badNums;
    
        for (const auto &nums : entry.phones) { 
            if (!valid(nums)) {
                badNums << " " << nums; 
            } else
                formatted << " " << format(nums);
            }
            if (badNums.str().empty()) {
                std::cout << entry.name << " " << formatted.str() << std::endl;
            } else {
                std::cerr << "input error: " 
                            << entry.name 
                            << " invalid number(s) " 
                            << badNums.str() << std::endl;
            }
    }

    return 0;
}