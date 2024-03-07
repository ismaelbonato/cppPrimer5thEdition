#include <iostream>
#include <fstream>
#include <sstream>


#include "SalesData.h"

int main(int argc, char *argv[])
{
    if (argc <= 1) {
        std::cerr << "No file?!" << std::endl;
        return -1; // indicate failure
    }

    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "error trying to open file?!" << std::endl;
        return -1; // indicate failure
    }

    SalesData total; // variable to hold data for the next transaction
    // read the first transaction and ensure that there are data to process
    if (file >> total.bookNo 
        >> total.units_sold 
        >> total.revenue) 
        {
        SalesData trans; // variable to hold the running sum
        // read and process the remaining transactions
        while (file >> trans.bookNo 
            >> trans.units_sold 
            >> trans.revenue) 
        {
            // if we're still processing the same book
            if (total.bookNo == trans.bookNo)
            {
                // update the running total
                total.bookNo = trans.bookNo;
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                // print results for the previous book        
                std::cout << total.bookNo 
                    << " " << total.units_sold 
                    << " " << total.revenue
                    << std::endl;
                
                // total now refers to the next book
                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
            }
        }
            // print the last transaction
            std::cout << total.bookNo 
                << " " << total.units_sold 
                << " " << total.revenue
                << std::endl;
    } else {
        // no input! warn the user
        std::cerr << "No data?!" << std::endl;
        return -1; // indicate failure
    }
    //------------------- End ----------------------

    return 0;
}
