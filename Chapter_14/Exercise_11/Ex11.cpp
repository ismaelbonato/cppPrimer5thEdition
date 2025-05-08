#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "SalesData.h"

int main()
{
    std::vector<SalesData> sdVec;
    std::string word;
    SalesData sd;

    while (std::cin >> sd) {
        sdVec.push_back(sd);
    }

    std::sort(sdVec.begin(), 
                        sdVec.end(), 
                        [] (const SalesData &a, const SalesData &b)
                        {return a.isbn() < b.isbn();}
    );

    for (const auto &sItem : sdVec) {
        std::cout << sItem << std::endl;
    }

    return 0;
}
