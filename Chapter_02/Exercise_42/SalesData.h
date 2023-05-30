#ifndef SalesData_H
#define SalesData_H
#include <string>

struct SalesData {
    std::string bookNo;
    std::string name;
    unsigned unitsSold = 0;
    double price = 0.0;
    double discount = 0.0; //in %
    double revenue = 0.0;
};

#endif