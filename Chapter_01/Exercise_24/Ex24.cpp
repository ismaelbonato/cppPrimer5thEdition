#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item currentItem, nextItem;
    int count;

    if(std::cin >> currentItem) {
        count = 1;
        while(std::cin >> nextItem) {
            if(currentItem.isbn() == nextItem.isbn()) {
                count++;
            } else {
                std::cout << "item " << currentItem << " " << count  << " times" <<std::endl;
                currentItem = nextItem;
                count = 1;
            }
        }
        std::cout << "item " << currentItem << " 1" << " times" <<std::endl;
    }
    return 0;
}


// Run ./a.out <input
