#include "StrBlob.h"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>
#include "StrBlobPtr.h"

int main ()
{
    StrBlob b1;
    std::ifstream file("input");
    std::string line;

    while (std::getline(file,line)) {
        b1.push_back(line);
    }

    auto b = b1.begin();
    auto e = b1.end();

    for (std::size_t idx = 0; idx < (b1.size() - 1); ++idx) {
        b.incr();
        std::cout << b.deref() << std::endl;
    }

    return 0;
}