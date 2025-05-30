#include "Vec.h"
#include <vector>
#include <string>

int main()
{     
    Vec<std::string> s;

    s.push_back("Hello");
    s.push_back("World");

    for (size_t i = 0; i < s.size(); i++)
    {
        std::cout << s[i] << ' ';
    }
    
    std::cout << std::endl;
}