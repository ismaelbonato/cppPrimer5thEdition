#include <iostream>
int main()
{
    int begin, end;
    std::cin >> begin >> end;

    std::cout << "first value: "<< begin << " second value: " << end << std::endl;

    if(begin < end) {
        while (begin <= end) {
            std::cout << "Number: " << begin << std::endl;
            ++begin;
        }
    } else {
        while (begin >= end) {
            std::cout << "Number: " << begin << std::endl;
            --begin;
        }
    }

    return 0;
}
