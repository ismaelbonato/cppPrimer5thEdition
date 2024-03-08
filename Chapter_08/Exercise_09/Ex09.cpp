#include <iostream>
#include <string>
#include <sstream>


std::istream &printStream(std::istream &is)
{
    std::string word;
    while (is >> word) {
        std::cout << word << " " ;
    }

    std::cout << std::endl;

    std::cin.clear();
    
    return std::cin;
}

int main() 
{
    std::istringstream iss("test one two three four five");

    printStream(iss);

    return 0;
}