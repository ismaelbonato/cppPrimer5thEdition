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
    SalesData itemData1, itemData2, itemSum;

    // Ex41_21.out < input 
    //-------------- Exercise 21 -------------------
    std::cin >> itemData1.bookNo 
        >> itemData1.units_sold 
        >> itemData1.revenue;

    std::cin >> itemData2.bookNo 
        >> itemData2.units_sold 
        >> itemData2.revenue;

    itemSum.bookNo = itemData1.bookNo;
    itemSum.units_sold = itemData1.units_sold + itemData2.units_sold;
    itemSum.revenue = itemData1.revenue + itemData2.revenue;

    std::cout << itemSum.bookNo 
        << " " << itemSum.units_sold 
        << " " << itemSum.revenue
        << std::endl;  
    //------------------- End ----------------------

    return 0;
}