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
    SalesData itemDataCur, itemDataNext;
    int count = 0;

    // Ex41_23.out < input_23_24_25
    //-------------- Exercise 23 -------------------
    if(std::cin >> itemDataCur.bookNo 
        >> itemDataCur.units_sold 
        >> itemDataCur.revenue) 
    {
        count = 1;
        
        while (std::cin >> itemDataNext.bookNo 
            >> itemDataNext.units_sold 
            >> itemDataNext.revenue)
        {
             if(itemDataCur.bookNo == itemDataNext.bookNo) {
                count++;
            } else {
                        
                std::cout << itemDataCur.bookNo 
                    << " " << itemDataCur.units_sold 
                    << " " << itemDataCur.revenue
                    << " " << count  << " times" <<std::endl;

                itemDataCur.bookNo = itemDataNext.bookNo;
                itemDataCur.units_sold = itemDataNext.units_sold;
                itemDataCur.revenue = itemDataNext.revenue;
                
                count = 1;
            }    
        }        

        std::cout << itemDataCur.bookNo 
            << " " << itemDataCur.units_sold 
            << " " << itemDataCur.revenue
            << " " << count  << " times" <<std::endl;
        
    }
    //------------------- End ----------------------

    return 0;
}