#include <iostream>
int main()
{
    int begin, end;
    std::cin >> begin >> end;

    std::cout << "first value: "<< begin << " second value: " << end << std::endl;


    while (begin <= end) {
        std::cout << "Number: " << begin << std::endl;
        ++begin;
    }

    return 0;
}
