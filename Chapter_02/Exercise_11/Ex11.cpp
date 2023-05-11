#include <iostream>

int main() {

    // a
    // Definition of a extern variable, it's an error.
    extern int ix = 1024;

    // b
    // Definition of iy
    int iy;

    // c
    // only declaraion without definition, extern defined elsewhere
    extern int iz;


    return 0;
}
