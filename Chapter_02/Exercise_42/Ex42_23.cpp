#include "SalesData.h"
#include <iostream>

int main()
{
    SalesData itemDataCur, itemDataNext;
    int count = 0;

    // Ex41_23.out < input_23_24_25
    //-------------- Exercise 23 -------------------
    if (std::cin >> itemDataCur.bookNo >> itemDataCur.unitsSold >> itemDataCur.revenue) {
        count = 1;

        while (std::cin >> itemDataNext.bookNo >> itemDataNext.unitsSold
               >> itemDataNext.revenue) {
            if (itemDataCur.bookNo == itemDataNext.bookNo) {
                count++;
            } else {
                std::cout << itemDataCur.bookNo << " " << itemDataCur.unitsSold << " "
                          << itemDataCur.revenue << " " << count << " times" << std::endl;

                itemDataCur.bookNo = itemDataNext.bookNo;
                itemDataCur.unitsSold = itemDataNext.unitsSold;
                itemDataCur.revenue = itemDataNext.revenue;

                count = 1;
            }
        }

        std::cout << itemDataCur.bookNo << " " << itemDataCur.unitsSold << " "
                  << itemDataCur.revenue << " " << count << " times" << std::endl;
    }
    //------------------- End ----------------------

    return 0;
}