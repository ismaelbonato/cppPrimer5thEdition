#include <iostream>
#include <string>

void f() {
    std::cout << "function called void f()" << std::endl;
}
void f(int) {
    std::cout << "function called void f(int)" << std::endl;
}
void f(int, int) {
    std::cout << "function called void f(int, int)" << std::endl;
}
void f(double, double = 3.14) {
    std::cout << "function called void f(double, double = 3.14)" << std::endl;
}


int main ()
{   
    //f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    
    return 0;
}