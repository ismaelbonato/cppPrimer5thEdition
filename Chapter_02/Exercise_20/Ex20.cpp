#include <iostream>

int main() {

    // definition of an integer with literao integer of value 42
    int i = 42;
    // definition of a integer pointer with the address of the variable i
    int *p1 = &i;
    // It's i^2 = i squared, using the pointer to the i address and after an assignment to i
    *p1 = *p1 * *p1;

    std::cout << "p1: " << *p1  << " i: " << i << std::endl;

    return 0;
}
