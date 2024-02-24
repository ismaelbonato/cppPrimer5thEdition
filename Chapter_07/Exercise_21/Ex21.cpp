#include <iostream>
#include "SalesData.h"

int main()
{
    SalesData total = std::cin;
    if (total.isbn() != "") {
        SalesData trans = std::cin;
        while(std::cin) {
            if (total.isbn() == trans.isbn()) 
                total.combine(trans); 
            else {
                print(std::cout, total) << std::endl;
                total = trans; 
            }
            read(std::cin, trans);
        }
        print(std::cout, total) << std::endl; 
    } else { // there was no input
        std::cerr << "No data?!" << std::endl; // notify the user
    }
    return 0;
}
