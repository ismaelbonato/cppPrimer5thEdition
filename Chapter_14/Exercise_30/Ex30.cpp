#include "StrBlob.h"
#include "ConstStrBlobPtr.h"
#include "StrBlobPtr.h"
#include <vector>
#include <iostream>

int main()
{
    StrBlob a1;
    a1.push_back("Hello");
    a1.push_back("World");
    a1.push_back("!");

    auto ret = a1.begin();

    std::cout << *ret << std::endl;
    std::cout << (ret + 1)->c_str() << std::endl;
    std::cout << *(ret + 2) << std::endl;

    auto csIt = a1.cbegin();

    std::cout << *csIt << std::endl;
    std::cout << (csIt + 1)->c_str() << std::endl;
    std::cout << *(csIt + 2) << std::endl;

    return 0;
}
