#include <iostream>
#include "SalesData.h"

int main()
{
    SalesData itemData1;
    // Ex41_20.out < input_20_21_22
    //-------------- Exercise 20 -------------------
    while (std::cin >> itemData1.bookNo 
        >> itemData1.units_sold 
        >> itemData1.price)
    {
        std::cout << itemData1.bookNo 
            << " " << itemData1.units_sold 
            << " " << itemData1.price
            << std::endl;  
    }
    //------------------- End ----------------------

    return 0;
   
}