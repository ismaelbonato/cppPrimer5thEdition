#include <iostream>
#include <functional>

int main ()
{

    int n = 5;
    std::function<bool(void)> f = [&n] (void) 
                                {return (n == 0) ? true : (--n, false);};

    std::cout << std::boolalpha;

    std::cout << "n(" << n << ")== 0 -> " << f() << std::endl;
    std::cout << "n(" << n << ")== 0 -> " << f() << std::endl;
    std::cout << "n(" << n << ")== 0 -> " << f() << std::endl;
    std::cout << "n(" << n << ")== 0 -> " << f() << std::endl;
    std::cout << "n(" << n << ")== 0 -> " << f() << std::endl;
    std::cout << "n(" << n << ")== 0 -> " << f() << std::endl;
    std::cout << "n(" << n << ")== 0 -> " << f() << std::endl;
    std::cout << "n(" << n << ")== 0 -> " << f() << std::endl;

    return 0;
}