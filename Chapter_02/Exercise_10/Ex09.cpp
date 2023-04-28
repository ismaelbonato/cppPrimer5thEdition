#include <iostream>

int main() {

    // (a)
    // cin stream needs a variable previously defined
    //std::cin >> int input_value;
    int input_value;
    std::cin >> input_value;

    //  (b)
    // when initialize a variable with curly braces the compiler
    // verifies if there is no data loss on casting convertion.
    //int i = { 3.14 };
    int i = { (int)3.14 };

    // (c)
    // You the previous declaration of wage
    // double salary = wage = 9999.99;
    double wage;
    double salary = wage = 9999.99;

    // it works but the compiler will perform a casting convertion
    // and data will be lost.
    int i2 = 3.14;

    return 0;
}
