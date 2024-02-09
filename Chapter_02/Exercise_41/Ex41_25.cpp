#include <iostream>

struct SalesData {
    std::string bookNo;
    std::string bookName;
    unsigned units_sold = 0;
    double price = 0.0;
    double discount = 0.0; //in %
    double revenue = 0.0;
};

//-------------- Exercise 25 -------------------
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
            if (total.bookNo == trans.bookNo)
            {
                // update the running total
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
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
                //total.revenue = trans.revenue;
            }
        }
            // print the last transaction
                std::cout << total.bookNo 
                    << " " << total.units_sold
                    << " " << total.revenue
                    << " " << (total.revenue)
                    << std::endl;
    } else {
        // no input! warn the user
        std::cerr << "No data?!" << std::endl;
        return -1; // indicate failure
    }
    //------------------- End ----------------------

    return 0;
}