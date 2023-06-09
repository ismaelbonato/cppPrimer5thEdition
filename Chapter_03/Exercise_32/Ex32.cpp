#include <cstddef>
#include <iterator>
#include <ostream>
#include <string>
#include <iostream>
#include <vector>

int main()
{
    
    // Part A
    int arr[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2[10];

    for (std::size_t idx = 0; idx < sizeof(arr)/sizeof(int); idx++) {
        arr2[idx] = arr[idx];
    }

    for (auto a : arr2) {
        std::cout << a << " ";
    }

    std::cout << std::endl;
    // Part B

    std::vector<int> iVec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> iVec2;

    iVec2 = iVec;

    for (auto v : iVec2) {
        std::cout << v << " ";
    }

    return 0;
}