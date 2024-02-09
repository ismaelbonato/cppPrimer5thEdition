#include <iostream>
#include "SalesData.h"

int main()
{
    SalesData total; // variable to hold data for the next transaction
    // read the first transaction and ensure that there are data to process
    if (read(std::cin, total)) 
        {
        SalesData trans; // variable to hold the running sum
        // read and process the remaining transactions
        while (read(std::cin, trans)) 
        {
            // if we're still processing the same book
            if (total.isbn() == trans.isbn())
            {
                // update the running total
                total = add(total, trans);
            } else {
                // print results for the previous book        
                print(std::cout, total);
                
                // total now refers to the next book
                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
                total.price = trans.price;
            }
        }
            // print the last transaction
            print(std::cout, total);
    } else {
        // no input! warn the user
        std::cerr << "No data?!" << std::endl;
        return -1; // indicate failure
    }
    //------------------- End ----------------------

    return 0;
}
