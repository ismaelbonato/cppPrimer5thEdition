#include <iostream>

// Given a pointer p, can you determine whether p points to a valid object?
// If so, how? If not, why not?

int *pValid_1;

int main() {

    int i = 0;
    int *pValid_2 = &i;
    int *pNullPtr = nullptr;
    int *pInvalid;

    std::cout << "i: " << i << std::endl;
    std::cout << "pValid_1: " << pValid_1 << std::endl;
    std::cout << "pValid_2: " << pValid_2 << std::endl;
    std::cout << "pNullPtr: " << pNullPtr << std::endl;
    std::cout << "pInvalid: " << pInvalid << std::endl;
    
    return 0;
}
