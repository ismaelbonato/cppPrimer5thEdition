#include <string>
#include <iostream>
#include <vector>
#include <fstream>

int main()
{
    std::string letter;
    std::string normalLetter("aceimnorsuvwxz");
    std::string word, longest;

    std::ifstream file("letter.txt");
    if (!file.is_open()) {
        return -1;
    }

    while (file >> word) {
        if (word.find_first_not_of(normalLetter) != std::string::npos) {
            continue;
        }

        if (word.size() > longest.size()) {
            longest = word;
        }
    }
    
    std::cout << "The Longest Word without Ascenders and Descender is: " 
    << longest << std::endl;
   
    return 0;
}