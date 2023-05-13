#include <iostream>

int main() {

    int i = 0, &r1 = i; double d = 0, &r2 = d;

    // (a)
    // var d will be assigned with the value above
    r2 = 3.14159;
    // (b)
    // var d (double) will be assigned with the value of var i (integer)
    r2 = r1;
    // (c)
    // var i (integer) will be assigned with the value of var d (double) convertion will be performed
    i = r2;
    // (d)
    // var i (integer) will be assigned with the value of var d (double) convertion will be performed
    r1 = d;

    std::cout << "i: " << i << " d: " << d << " r1: " << r1 << " r2 " << r2 << std::endl;

    return 0;
}
