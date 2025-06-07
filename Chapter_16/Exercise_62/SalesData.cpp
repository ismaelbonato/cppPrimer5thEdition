#include "SalesData.h"

std::istream &operator>>(std::istream &is, SalesData &item)
{
    is >> item.bookNo >> item.units_sold >> item.price;
    item.revenue = item.units_sold * item.price;
    return is;
}

std::ostream &operator<<(std::ostream &os, const SalesData &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " "
       << item.avgPrice();
    return os;
}

SalesData &SalesData::operator+=(const SalesData &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

SalesData &SalesData::operator=(const std::string &rhs)
{   
    bookNo = rhs;
    return *this;
}

SalesData operator+(const SalesData &lhs, const SalesData &rhs)
{
    SalesData sum(lhs);
    sum += rhs;
    return sum;
}

bool operator==(const SalesData &lhs, const SalesData &rhs)
{
    return lhs.bookNo == rhs.bookNo &&
           lhs.units_sold == rhs.units_sold &&
           lhs.revenue == rhs.revenue;
}
