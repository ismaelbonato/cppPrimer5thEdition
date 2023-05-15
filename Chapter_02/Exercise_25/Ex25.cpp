#include <iostream>

int main() {

    // (a)
    // ip is a pointer non initialized it means its value is unknown
    // r is a reference to a pointer, it's ilegal, there is not a pointer modifier
    // before the address modifier.
    // int* ip, &r = ip;
    // (b)
    // i is an int  non initialized it means its value is unknown
    // ip is pointer to an integer
    int i, *ip = 0;
    // (c)
    // * ip is a pointer to an integer.
    // ip2 is an integer.
    // int* ip, ip2;

    return 0;
}
