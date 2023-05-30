#include <iostream>
#include "SalesData.h"

int main()
{
    SalesData itemData1, itemData2, itemSum;

    // Ex41_21.out < input 
    //-------------- Exercise 21 -------------------
    std::cin >> itemData1.bookNo 
        >> itemData1.unitsSold 
        >> itemData1.revenue;

    std::cin >> itemData2.bookNo 
        >> itemData2.unitsSold 
        >> itemData2.revenue;

    itemSum.bookNo = itemData1.bookNo;
    itemSum.unitsSold = itemData1.unitsSold + itemData2.unitsSold;
    itemSum.revenue = itemData1.revenue + itemData2.revenue;

    std::cout << itemSum.bookNo 
        << " " << itemSum.unitsSold 
        << " " << itemSum.revenue
        << std::endl;  
    //------------------- End ----------------------

    return 0;
}