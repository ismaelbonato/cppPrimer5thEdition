#ifndef SALESDATA_H
#define SALESDATA_H

#include <string>
#include <istream>
#include <ostream>

struct SalesData {
    std::string bookNo;
    std::string bookName;
    unsigned units_sold = 0;
    double price = 0.0;
    double discount = 0.0; //in %
    double revenue = 0.0;

    double avgPrice() const {return (revenue / units_sold); }
    std::string isbn() const { return bookNo; }
    const SalesData& combine(const SalesData &rhs);
};

const SalesData& SalesData::combine(const SalesData &rhs)
{
    units_sold += rhs.units_sold; // add the members of rhs into
    revenue += rhs.revenue; // the members of ''this'' object
    return *this; // return the object on which the function was called
}

std::istream &read(std::istream &inputStream, SalesData &item)
{
    inputStream >> item.bookNo >> item.units_sold >> item.price;
    item.revenue = item.price * item.units_sold;
    return inputStream;
}

std::ostream &print(std::ostream &outputStream, const SalesData &item)
{
    outputStream << item.isbn() << " " << item.units_sold << " "
    << " " << item.revenue << " " <<  item.avgPrice()  
    << " " << std::endl;
    return outputStream;
}

SalesData add(const SalesData &lhs, const SalesData &rhs)
{
    SalesData sum = lhs; 
    sum.combine(rhs); 
    return sum;
}

#endif // SALESDATA_H