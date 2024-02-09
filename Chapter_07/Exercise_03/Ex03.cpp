#include <iostream>
#include "SalesData.h"

int main()
{
    SalesData total; // variable to hold data for the next transaction
    // read the first transaction and ensure that there are data to process
    if (std::cin >> total.bookNo 
        >> total.units_sold 
        >> total.price)
        {
        total.revenue = total.price * total.units_sold;
        SalesData trans; // variable to hold the running sum
        // read and process the remaining transactions
        while (std::cin >> trans.bookNo 
            >> trans.units_sold
            >> trans.price)
        {
            trans.revenue = trans.price * trans.units_sold;
            // if we're still processing the same book
            if (total.isbn() == trans.isbn())
            {
                // update the running total
                total.combine(trans);
            } else {
                // print results for the previous book        
                std::cout << total.bookNo 
                    << " " << total.units_sold
                    << " " << total.revenue
                    << " " << (total.revenue / total.units_sold)
                    << std::endl;
                
                // total now refers to the next book
                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.price = trans.price;
                total.revenue = trans.revenue;
            }
        }
            // print the last transaction
                std::cout << total.bookNo 
                    << " " << total.units_sold
                    << " " << total.revenue
                    << " " << (total.revenue / total.units_sold)
                    << std::endl;
    } else {
        // no input! warn the user
        std::cerr << "No data?!" << std::endl;
        return -1; // indicate failure
    }
    //------------------- End ----------------------

    return 0;
}
