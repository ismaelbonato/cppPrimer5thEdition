#include <iostream>

int main()
{
    // Worng
    //std::cout << "/*" << std::endl;
    //std::cout << "*/" << std::endl;
    //std::cout << /* "*/" */;
    //std::cout << /* "*/" /* "/*" */ << //std::endl;

    // Correct
    std::cout << "/*" << std::endl;
    std::cout << "*/" << std::endl;
    std::cout << /* "*/" */" << std::endl;
    std::cout << /* "*/" /* "/*" */ << std::endl;

    return 0;
}
