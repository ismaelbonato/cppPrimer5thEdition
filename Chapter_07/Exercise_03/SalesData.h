#ifndef SALESDATA_H
#define SALESDATA_H

#include <string>

struct SalesData {
    std::string bookNo;
    std::string bookName;
    unsigned units_sold = 0;
    double price = 0.0;
    double discount = 0.0; //in %
    double revenue = 0.0;

    std::string isbn() const { return bookNo; }
    const SalesData& combine(const SalesData &rhs);

};

const SalesData& SalesData::combine(const SalesData &rhs)
{
    units_sold += rhs.units_sold; // add the members of rhs into
    revenue += rhs.revenue; // the members of ''this'' object
    return *this; // return the object on which the function was called
}

#endif // SALESDATA_H