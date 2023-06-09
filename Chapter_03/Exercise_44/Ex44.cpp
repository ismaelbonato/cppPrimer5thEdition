#include <cstddef>
#include <iterator>
#include <ostream>
#include <string>
#include <iostream>
#include <vector>

#include <cstring>

int main()
{   
    int ia[3][4] = {0, 1, 2, 3, 
                    4, 5, 6, 7,
                    8, 9, 10, 11};

    using int_array = int[4];


    { // first version

        std::cout << "First version: ";

        for (int_array &row : ia) {
            for (int col: row) {
                std::cout << col;
            }
        }
        std::cout << std::endl;
    }

    { // second version

        std::cout << "Second version: ";

        for (size_t x = 0; x < 3; x++) {
            for (size_t y = 0; y < 4; y++) {
                std::cout << ia[x][y];
            }

        }
        std::cout << std::endl;
    }
    
    { // third version

        std::cout << "Third version: ";

        for (int_array *x = ia; x < ia + 3; x++) {
           for (int *y = *x; y < (*x + 4); y++) {
                std::cout << *y;
            }
        }
        std::cout << std::endl;
    }

    return 0;
}