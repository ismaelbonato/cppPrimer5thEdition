#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "SalesData.h"

int main()
{
    SalesData sales{"0-201-99999-9", 10, 10};

    std::string salesBook = sales;
    double salesRev = sales;
    
    std::cout << "BookNo: " << salesBook << " Revenue: " << salesRev << std::endl;

    return 0;
}