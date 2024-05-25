#include <vector>
#include <string>
#include <iostream>

int main() 
{
    const std::vector<std::string> iVec{"1", "2", "3", "4"};
    const std::vector<std::string> sVec{"1.2", "3.4", "5.6"};

    int sumInt = 0;
    double sumDouble = 0;

    for (auto number: iVec) {
        sumInt += std::stoi(number);
    }
    std::cout << "The sum of all values in iVec is: " << sumInt << std::endl;

    for (auto number : sVec) {
        sumDouble += std::stod(number);
    }
    std::cout << "The sum of all values in sVec is: " << sumDouble << std::endl;


    return 0;
}