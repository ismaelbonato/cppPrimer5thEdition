#include <iostream>

struct SalesData {
    std::string bookNo;
    std::string bookName;
    unsigned units_sold = 0;
    double price = 0.0;
    double discount = 0.0; //in %
    double revenue = 0.0;
    double avgPrice = 0.0;
};

using std::cin;
using std::cout;
using std::endl;

int main()
{
    SalesData itemData1, itemData2, itemSum;

    // Ex41_21.out <  input_20_21_22
    //-------------- Exercise 21 -------------------
    cin >> itemData1.bookNo 
        >> itemData1.units_sold 
        >> itemData1.price;
    itemData1.revenue = itemData1.price * itemData1.units_sold;

    cin >> itemData2.bookNo 
        >> itemData2.units_sold 
        >> itemData2.price;

    itemData2.revenue = itemData2.price * itemData2.units_sold;

    itemSum.bookNo = itemData1.bookNo;
    itemSum.units_sold = itemData1.units_sold + itemData2.units_sold;
    itemSum.revenue = itemData1.revenue + itemData2.revenue;
    itemSum.avgPrice = itemSum.revenue / itemSum.units_sold;

    cout << itemSum.bookNo 
        << " " << itemSum.units_sold 
        << " " << itemSum.revenue
        << " " << itemSum.avgPrice
        << endl;  
    //------------------- End ----------------------

    return 0;
}
