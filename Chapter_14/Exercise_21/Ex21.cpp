#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "SalesData.h"

int main()
{
    SalesData sales1{"0-201-99999-9", 10, 10};

    sales1 = sales1 + sales1;

    sales1 += sales1;

    std::cout << sales1 << std::endl;

    return 0;
}