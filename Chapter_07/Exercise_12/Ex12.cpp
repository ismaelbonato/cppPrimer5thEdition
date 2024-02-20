#include <iostream>
#include "SalesData.h"

int main()
{
    SalesData data1;
    print(std::cout, data1);

    SalesData data2{"0-201-78345-X"};
    print(std::cout, data2);

    SalesData data3{"0-201-78345-X", 3, 10};
    print(std::cout, data3);

    SalesData data4{std::cin};
    print(std::cout, data4);

    return 0;
}
