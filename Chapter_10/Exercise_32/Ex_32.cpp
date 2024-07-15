#include <iostream>
#include "Sales_item.h"
#include <iterator>
#include <vector>
#include <algorithm>
#include <numeric>

bool compareISBN(const Sales_item &sd1, const  Sales_item &sd2)
{
    return sd1.isbn() < sd2.isbn();
}

int main()
{
    std::istream_iterator<Sales_item> item_iter(std::cin), eof;
    std::vector<Sales_item> sV(item_iter, eof);

    std::sort(sV.begin(), sV.end(), compareISBN);

    auto begin = sV.begin();
    while (begin != sV.end()) {
        auto newBegin = std::find_if_not( begin, sV.end(), 
            [begin]
            (const Sales_item &item) -> bool
            {return (begin->isbn() == item.isbn());}
        );

        Sales_item sum = std::accumulate(begin, newBegin, Sales_item(begin->isbn()));
        std::cout << sum << std::endl;
 
        begin = newBegin;
    };

    return 0;
}
