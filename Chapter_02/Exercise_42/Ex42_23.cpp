#include "SalesData.h"
#include <iostream>

int main()
{
    SalesData itemDataCur, itemDataNext;
    int count = 0;

    // Ex41_23.out < input_23_24_25
    //-------------- Exercise 23 -------------------
    if(std::cin >> itemDataCur.bookNo 
        >> itemDataCur.units_sold 
        >> itemDataCur.price) 
    {
        itemDataCur.revenue = itemDataCur.price * itemDataCur.units_sold;
        count = 1;
        
        while (std::cin >> itemDataNext.bookNo 
            >> itemDataNext.units_sold 
            >> itemDataNext.price)
        {
            if(itemDataCur.bookNo == itemDataNext.bookNo) {
                count++;
            } else {
                        
                std::cout << itemDataCur.bookNo 
                    << " " << count  << " times" <<std::endl;

                itemDataCur.bookNo = itemDataNext.bookNo;
                itemDataCur.units_sold = itemDataNext.units_sold;
                itemDataCur.revenue = itemDataNext.revenue;
                
                count = 1;
            }    
        }        

        std::cout << itemDataCur.bookNo 
            << " " << count  << " times" <<std::endl;
        
    }
    //------------------- End ----------------------

    return 0;
}