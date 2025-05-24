#include <iostream>
#include "SalesData.h"

template <typename T> int compare(const T &a, const T &b)
{
    if (a < b) return -1;
    if (a > b) return 1;

    return 0;
}

int main()
{
    SalesData sales1{"0-201-99999-9", 10, 10};
    SalesData sales2{"0-201-78346-X", 3, 20};

    compare(sales1, sales2);    


    return 0;
}