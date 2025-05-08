#ifndef SALESDATA_H
#define SALESDATA_H

#include <iostream>
#include <istream>
#include <ostream>
#include <string>

struct SalesData
{
    friend SalesData operator+(const SalesData &lhs, const SalesData &rhs);
    friend std::istream &operator>>(std::istream &is, SalesData &item);
    friend std::ostream &operator<<(std::ostream &os, const SalesData &item);

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double price = 0.0;
    double revenue = 0.0;

    inline double avgPrice() const { return (revenue / units_sold); };

public:
    // constructors added

    SalesData(const std::string &s, unsigned n, double p)
        : bookNo(s)
        , units_sold(n)
        , revenue(p * n)
    {}

    SalesData(const std::string &s)
        : SalesData(s, 0, 0.0){};

    SalesData()
        : SalesData(""){};

    SalesData(std::istream &inputStream)
        : SalesData()
    {
        inputStream >> *this;
    };

    SalesData &operator+=(const SalesData &rhs);
    SalesData &operator=(const std::string &rhs);

    std::string isbn() const { return bookNo; }
};


#endif // SALESDATA_H