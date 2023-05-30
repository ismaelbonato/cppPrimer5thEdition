#include <iostream>
#include "SalesData.h"

int main()
{
    SalesData itemData1;
    // Ex42_20.out < input_20_21_22
    //-------------- Exercise 20 -------------------
    while (std::cin >> itemData1.bookNo 
        >> itemData1.unitsSold 
        >> itemData1.revenue)
    {
        std::cout << itemData1.bookNo 
            << " " << itemData1.unitsSold 
            << " " << itemData1.revenue
            << std::endl;  
    }
    //------------------- End ----------------------

    return 0;
   
}