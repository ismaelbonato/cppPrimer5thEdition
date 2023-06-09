#include <cstddef>
#include <iterator>
#include <ostream>
#include <string>
#include <iostream>
#include <vector>

int main()
{
    
    int arr[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    //int *b = std::begin(arr);
    //int *e = std::end(arr);

    
    for (auto a : arr) {
        std::cout << a << ' ';
    }

    for (auto b = std::begin(arr); b != std::end(arr); b++) {
        *b = 0;
    }
    
    std::cout << std::endl;


    for (auto a : arr) {
        std::cout << a << ' ';
    }


    return 0;
}