#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "SalesData.h"


bool compareISBN(const SalesData &sd1, const SalesData &sd2)
{
    return sd1.isbn() < sd2.isbn();
}

int main()
{
    std::vector<SalesData> sdVec;
    std::string word;
    SalesData sd;

    while (read(std::cin, sd)) {
        sdVec.push_back(sd);
    }

    std::sort(sdVec.begin(), sdVec.end(), compareISBN);

    for (const auto &sItem : sdVec) {
        print(std::cout, sItem);
        std::cout << std::endl;
    }

    return 0;
}
