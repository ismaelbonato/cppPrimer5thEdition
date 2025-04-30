#include <string>
#include <memory>

#include "StrVec.h"

int main()
{
    StrVec vec{{"Hello"}, {"World"}, {"C++"}};

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}