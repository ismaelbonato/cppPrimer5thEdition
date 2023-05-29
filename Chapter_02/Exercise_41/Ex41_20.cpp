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
    SalesData itemData1;
    // Ex41_20.out < input 
    //-------------- Exercise 20 -------------------
    while (std::cin >> itemData1.bookNo 
        >> itemData1.units_sold 
        >> itemData1.revenue)
    {
        std::cout << itemData1.bookNo 
            << " " << itemData1.units_sold 
            << " " << itemData1.revenue
            << std::endl;  
    }
    //------------------- End ----------------------

    return 0;
   
}