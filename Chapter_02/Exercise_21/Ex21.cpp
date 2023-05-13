#include <iostream>

int main() {

    int i = 0;

    // (a)
    // I's ilegal because a poiter need to have the same type
    double* dp = &i;

    // (b)
    // it's invalid, because i is not a address type, it miss the address operator.
    int *ip = i;

    //(c)
    // It's valid
    int *p = &i;

    return 0;
}
