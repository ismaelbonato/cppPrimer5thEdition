#include "Vec.h"
#include <vector>
#include <string>

int main()
{     
    Vec<std::string> sVec;
    std::string s{"Hello"};

    sVec.emplace_back(10, '!');
    sVec.emplace_back("Hellow World!");
    
    sVec.emplace_back(s);


    
    for (size_t i = 0; i < sVec.size(); i++)
    {
        std::cout << sVec[i];
    }
    
    std::cout << std::endl;
}