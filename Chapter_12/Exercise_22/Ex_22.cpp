#include "StrBlob.h"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>
#include "StrBlobPtr.h"
#include "ConstStrBlobPtr.h"


int main ()
{
    const StrBlob b1;
    std::ifstream file("input");
    std::string line;

    while (std::getline(file,line)) {
        b1.push_back(line);
    }
    
    auto b = b1.cbegin();

    for (std::size_t idx = 0; idx < (b1.size() -1 ); ++idx) {
        b.incr();
        std::cout << b.deref() << std::endl;
    }

    return 0;
}