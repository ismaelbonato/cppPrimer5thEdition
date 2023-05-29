#include <iostream>

struct SalesData {
    std::string bookNo;
    std::string bookName;
    unsigned units_sold = 0;
    double price = 0.0;
    double discount = 0.0; //in %
    double revenue = 0.0;
};

int main()
{
    SalesData itemData1, itemDataSum;

    // Ex41_22.out < input 
    //-------------- Exercise 22 -------------------
    while (std::cin >> itemData1.bookNo 
        >> itemData1.units_sold 
        >> itemData1.revenue)
    {
        itemDataSum.units_sold += itemData1.units_sold;
        itemDataSum.revenue += itemData1.revenue;
    }
    itemDataSum.bookNo = itemData1.bookNo;


    std::cout << itemDataSum.bookNo 
                << " " << itemDataSum.units_sold 
                << " " << itemDataSum.revenue
                << std::endl;
    
    
    //------------------- End ----------------------

    return 0;
}