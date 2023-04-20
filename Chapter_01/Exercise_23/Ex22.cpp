#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item sum, item;

    if(!(std::cin >> sum)) {
        return -1;
    }

    while(std::cin >> item) {
        if(sum.isbn() == item.isbn())
            sum += item;
    }
    std::cout << sum << std::endl;
    return 0;
}


// Run ./a.out <input
