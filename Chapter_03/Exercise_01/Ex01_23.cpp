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

// Ex41_23.out < input_23_24_25
//-------------- Exercise 23 -------------------
int main()
{
    SalesData itemDataCur, itemDataNext;
    int count = 0;

    // Ex41_23.out < input_23_24_25
    //-------------- Exercise 23 -------------------
    if(cin >> itemDataCur.bookNo 
        >> itemDataCur.units_sold 
        >> itemDataCur.price) 
    {
        itemDataCur.revenue = itemDataCur.price * itemDataCur.units_sold;
        count = 1;
        
        while (cin >> itemDataNext.bookNo 
            >> itemDataNext.units_sold 
            >> itemDataNext.price)
        {
            if(itemDataCur.bookNo == itemDataNext.bookNo) {
                count++;
            } else {
                        
                cout << itemDataCur.bookNo 
                    << " " << count  << " times" <<endl;

                itemDataCur.bookNo = itemDataNext.bookNo;
                itemDataCur.units_sold = itemDataNext.units_sold;
                itemDataCur.revenue = itemDataNext.revenue;
                
                count = 1;
            }    
        }        

        cout << itemDataCur.bookNo 
            << " " << count  << " times" <<endl;
        
    }
    //------------------- End ----------------------

    return 0;
}
//------------------- End ----------------------