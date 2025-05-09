#include "StrBlob.h"
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

    std::cout << (ret).deref() << std::endl;
    std::cout << (ret + 1).deref() << std::endl;
    std::cout << (ret + 2).deref() << std::endl;

    auto end = a1.end();

    std::cout << (end - 3).deref() << std::endl;
    std::cout << (end - 2).deref() << std::endl;
    std::cout << (end - 1).deref() << std::endl;




    return 0;
}
