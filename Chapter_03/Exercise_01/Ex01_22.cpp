#include <iostream>

struct SalesData {
    std::string bookNo;
    std::string bookName;
    unsigned units_sold = 0;
    double price = 0.0;
    double discount = 0.0; //in %
    double revenue = 0.0;
};

using std::cin;
using std::cout;
using std::endl;

// Ex41_22.out < input_20_21_22
//-------------- Exercise 22 -------------------
int main()
{
    SalesData itemData1, itemDataSum;

    while (cin >> itemData1.bookNo 
        >> itemData1.units_sold 
        >> itemData1.price)
    {
        itemData1.revenue = itemData1.price * itemData1.units_sold;
        itemDataSum.units_sold += itemData1.units_sold;
        itemDataSum.revenue += itemData1.revenue;
    }
    itemDataSum.bookNo = itemData1.bookNo;


    cout << itemDataSum.bookNo 
                << " " << itemDataSum.units_sold 
                << " " << itemDataSum.revenue
                << endl;
    
    
    //------------------- End ----------------------

    return 0;
}
//------------------- End ----------------------