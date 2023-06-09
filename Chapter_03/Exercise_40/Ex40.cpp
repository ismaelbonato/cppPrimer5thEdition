#include <cstddef>
#include <iterator>
#include <ostream>
#include <string>
#include <iostream>
#include <vector>

#include <cstring>

int main()
{   
    char s1[50] = "Hello";
    char s2[50] = "World";
    char sr[100];

    std::strcpy(sr, s1);
    std::strcat(sr, " ");
    std::strcat(sr, s2);
    std::strcat(sr, "!!!");

    for (auto ch : sr) {
        std::cout << ch;
    }

    std::cout << std::endl;

    return 0;
}