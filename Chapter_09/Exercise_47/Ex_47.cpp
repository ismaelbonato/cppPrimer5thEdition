#include <string>
#include <iostream>
#include <vector>

//-------------- find_first_of ------------------
std::vector<unsigned int> findNumbers(const std::string &s)
{
    std::string numbers("0123456789");
    std::string::size_type pos = 0;
    std::vector<unsigned int> result;

    while ((pos = s.find_first_of(numbers, pos)) != std::string::npos ) {
        result.push_back(s.at(pos) - 0x30);
        ++pos;
    }

    return result;
}

//-------------- find_first_not_of ------------------
std::vector<char> findLetters(const std::string &s)
{
    std::string numbers("0123456789");
    std::string::size_type pos = 0;
    std::vector<char> result;

    while ((pos = s.find_first_not_of(numbers, pos)) != std::string::npos ) {
        result.push_back(s.at(pos));
        ++pos;
    }

    return result;
}

int main()
{
    std::string str("ab2c3d7R4E6");

    //-------------- find_first_of ------------------

    auto numbers = findNumbers(str);
    
    std::cout << numbers.size() << " numbers found:" << std::endl;

    for (auto number: numbers) {
        std::cout << number << ", ";
    }
        
    std::cout << std::endl;

    //-------------- find_first_not_of ------------------

    auto letters = findLetters(str);

    std::cout << letters.size() << " letters found:" << std::endl;

    for (auto letter: letters) {
        std::cout << letter << ", ";
    }
        
    std::cout << std::endl;

    return 0;
}