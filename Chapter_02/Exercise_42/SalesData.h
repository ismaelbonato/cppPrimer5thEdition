#ifndef SalesData_H
#define SalesData_H
#include <string>

struct SalesData {
    std::string bookNo;
    std::string name;
    unsigned units_sold = 0;
    double price = 0.0;
    double discount = 0.0; //in %
    double revenue = 0.0;
    double avgPrice = 0.0;
};

#endif