#include <string>
#include <memory>

#include "StrVec.h"



int main()
{

    StrVec vec1;
    vec1.push_back("Hello");
    vec1.push_back("World");

    StrVec vec2;
    vec2.push_back("C++");
    vec2.push_back("Programming");

    vec2 = vec1; // Use the assignment operator

    for (auto it = vec2.begin(); it != vec2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;



    return 0;
}