#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<char>  sVec{'H', 'E','L','L','O'};
    std::string str(sVec.begin(), sVec.end());

    std::cout << str << std::endl;

    return 0;
}