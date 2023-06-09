#include <cstddef>
#include <iterator>
#include <ostream>
#include <string>
#include <iostream>
#include <vector>

int main()
{   
    // array scope
    {
        std::cout << std::endl << "Array" << std::endl;

        int arr1[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int arr2[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        int *a1b = std::begin(arr1);
        int *a1e = std::end(arr1);
        
        int *a2b = std::begin(arr2);
        int *a2e = std::end(arr2);

        while ( (a1b < a1e) && (a2b < a2e) ) {
            if (*a1b != *a2b) {
                std::cout << "arrays are different" << std::endl;
                break;
            }
            std::cout << *a1b << *a2b << std::endl;


            a1b++;
            a2b++;
        }

        if ((a1b == a1e) && (a2b == a2e) ) {
            std::cout << "arrays are equal" << std::endl;
        } 
    }
    // vector scope
    {
        std::cout << std::endl << "Vector" << std::endl;

        std::vector<int> v1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::vector<int> v2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        
        if (v1 == v2) {
            std::cout << "arrays are equal" << std::endl;
        } else {
            std::cout << "arrays are different" << std::endl;
        }

    }

    return 0;
}