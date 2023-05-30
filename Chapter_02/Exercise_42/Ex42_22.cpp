#include <iostream>
#include "SalesData.h"

int main()
{
    SalesData itemData1, itemDataSum;

    // Ex41_22.out < input 
    //-------------- Exercise 22 -------------------
    while (std::cin >> itemData1.bookNo 
        >> itemData1.unitsSold 
        >> itemData1.revenue)
    {
        itemDataSum.unitsSold += itemData1.unitsSold;
        itemDataSum.revenue += itemData1.revenue;
    }
    itemDataSum.bookNo = itemData1.bookNo;


    std::cout << itemDataSum.bookNo 
                << " " << itemDataSum.unitsSold 
                << " " << itemDataSum.revenue
                << std::endl;
    //------------------- End ----------------------

    return 0;
}