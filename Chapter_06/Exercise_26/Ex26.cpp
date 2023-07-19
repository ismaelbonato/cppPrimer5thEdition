#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    for (int idx = 1; idx < argc; ++idx) {
        std::cout << argv[idx] << std::endl;
    }
    
    return 0;
}