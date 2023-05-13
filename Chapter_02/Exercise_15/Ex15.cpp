#include <iostream>

int main() {

    // (a)
    // It's valid but it's an assignment of an Floating point double literal to an Integer, the compiler will perform a type conversion.
    int ival = 1.01;
    // (b)
    // It's invalid because a reference needs a object to be initilized.
    //int &rval1 = 1.01;
    // (c)
    // It's valid &rval2 will be a reference to ival = 1
    int &rval2 = ival;
    // (d)
    // it' invalid because a reference needs an object to be initilized
    //int &rval3;

    std::cout << "ival: " << ival << " rval2: " << rval2 << std::endl;

    return 0;
}
 
