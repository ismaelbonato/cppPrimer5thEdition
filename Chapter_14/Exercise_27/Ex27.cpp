#include "StrBlob.h"
#include "StrBlobPtr.h"
#include <vector>
#include <iostream>

int main()
{
    std::cout << "StrBlob" << std::endl;

    StrBlob a1;
    a1.push_back("Hello");
    a1.push_back("World");
    a1.push_back("!");

    auto ret = a1.begin();

    std::cout << (ret++).deref() << std::endl;

    std::cout << ret.deref() << std::endl;

    std::cout << (++ret).deref() << std::endl;

    return 0;
}
