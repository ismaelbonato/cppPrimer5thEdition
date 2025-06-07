#include "SalesData.h"

#include <iostream>
#include <string>
#include <unordered_set>
#include <utility>

namespace std {
template<>
struct std::hash<SalesData>
{
    typedef size_t result_type;
    typedef SalesData argument_type; 

    size_t operator()(const SalesData& s) const;
};

size_t hash<SalesData>::operator()(const SalesData& s) const
{
    return hash<string>()(s.bookNo) ^
            hash<unsigned>()(s.units_sold) ^
            hash<double>()(s.revenue);
}

} // namespace std

int main()
{
    std::unordered_multiset<SalesData> bookSales;

    SalesData book1("978-3-16-148410-0", 10, 29.99);
    SalesData book2("978-3-16-148410-0", 5, 29.99);
    SalesData book3("978-1-23-456789-0", 3, 19.99);
    SalesData book4("978-0-12-345678-9", 7, 24.99);
    SalesData book5("978-0-12-345678-9", 2, 24.99);
    SalesData book6("978-9-87-654321-0", 1, 14.99);

    bookSales.insert(book1);
    bookSales.insert(book2);
    bookSales.insert(book3);
    bookSales.insert(book4);
    bookSales.insert(book5);
    bookSales.insert(book6);

    std::cout << "Number of unique books: " << bookSales.size() << std::endl;

    for (auto i : bookSales)
    {
        std::cout << i << std::endl;
    }

    return 0;
}