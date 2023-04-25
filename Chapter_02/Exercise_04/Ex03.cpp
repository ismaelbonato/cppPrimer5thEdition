#include <iostream>

int main() {

    unsigned u = 10, u2 = 42;
    int i = 10, i2 = 42;

    std::cout << u2 - u << std::endl; // Answer: 32
    std::cout << u - u2 << std::endl; // Answer: 2^32 - 32
    std::cout << i2 - i << std::endl; // Answer: 32
    std::cout << i - i2 << std::endl; // Answer: -32
    std::cout << i - u << std::endl;  // Answer: 0
    std::cout << u - i << std::endl;  // Answer: 0


    return 0;
}
