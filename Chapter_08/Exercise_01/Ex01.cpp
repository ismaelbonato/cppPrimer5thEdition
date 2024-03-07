#include <iostream>
#include <string>


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
    return 0;
}