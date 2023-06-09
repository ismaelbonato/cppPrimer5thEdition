#include <cstddef>
#include <iterator>
#include <ostream>
#include <string>
#include <iostream>
#include <vector>

#include <cstring>

int main()
{   
    // String scope
    {
        std::cout << "string Scope" << std::endl;

        std::string s1("123456");
        std::string s2("123456");

        if (s1 == s2) {
            std::cout << "Strings are equal" << std::endl;
        } else {
            std::cout << "Strings are different" << std::endl;
        }
    }
    // C-Style string array scope
    {
        std::cout << "C-Style string array scope " << std::endl;

        char a1[] = "123456";
        char a2[] = "123456";

        if (std::strcmp(a1, a2) == 0) {
            std::cout << "Strings are equal" << std::endl;
        } else {
            std::cout << "Strings are different" << std::endl;
        }
    }

    return 0;
}