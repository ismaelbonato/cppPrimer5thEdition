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

// Ex01_20.out < input_20_21_22
//-------------- Exercise 20 -------------------
int main()
{
    SalesData itemData1;

    while (cin >> itemData1.bookNo 
        >> itemData1.units_sold 
        >> itemData1.revenue)
    {
        cout << itemData1.bookNo 
            << " " << itemData1.units_sold 
            << " " << itemData1.revenue
            << endl;  
    }

    return 0;
   
}
//------------------- End ----------------------
