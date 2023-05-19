#include <iostream>

// string global = empty
std::string global_str;
// global_int = 0
int global_int;

int main()
{
    // local_int = undefined
    int local_int;
    // local_str = empty
    std::string local_str;

    std::cout << "global_str = " << global_str << std::endl;
    std::cout << "global_int = " << global_int << std::endl;
    std::cout << "local_int = " << local_int << std::endl;
    std::cout << "local_str = " << local_str << std::endl;

    return 0;
}
