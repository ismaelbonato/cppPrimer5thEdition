#include <iostream>

int main(void)
{
    int i = 0, &r = i;
    const int ci = i, &cr = ci;
    
    auto a = r; 
    auto b = ci; 
    auto c = cr; 
    auto d = &i; 
    auto e = &ci; 
    auto &g = ci;

    std::cout << "Before the assignment:" << std::endl 
        <<"a: " << a << std::endl 
        <<"b: " << b << std::endl 
        <<"c: " << c << std::endl 
        <<"d: " << *d << std::endl 
        <<"e: " << *e << std::endl 
        <<"g: " << g << std::endl;


    a = 42; 
    b = 42; 
    c = 42;
    //d = 42
    *d = 42; 
//  e = 42; 
//  g = 42;

    std::cout << "After the assignment:" << std::endl 
        <<"a: " << a << std::endl 
        <<"b: " << b << std::endl 
        <<"c: " << c << std::endl 
        <<"d: " << *d << std::endl 
        <<"e: " << *e << std::endl 
        <<"g: " << g << std::endl;




    return 0;
}
