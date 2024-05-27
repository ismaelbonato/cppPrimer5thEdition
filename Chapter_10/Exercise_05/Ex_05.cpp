#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>


int main ()
{
    std::vector<const char *> pcVec{"cpp", "Primer", "5TH"};
    std::vector<const char *> pcVec2{"cpp", "Primer", "5TH"};
    std::vector<std::string> pcVec3{"cpp", "Primer", "5TH"};
    
    std::vector<const char *> pcVec4;

    pcVec4.push_back("cpp");
    pcVec4.push_back("Primer");
    pcVec4.push_back("5TH");

    bool res = std::equal(
        pcVec3.cbegin(), 
        pcVec3.cend(), 
        pcVec4.cbegin());

    std::cout << "the result is: " << res << std::endl;
    std::cout << pcVec3.at(0) << " " << pcVec4.at(0) << std::endl; 

    return 0;
}