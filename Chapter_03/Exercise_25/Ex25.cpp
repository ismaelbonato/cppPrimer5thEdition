#include <iterator>
#include <ostream>
#include <string>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{1,2,3,4,5,6,7,8,9};
    for (auto it = v.begin(); it != (v.end()) ; it++) {
        *it *= *it;
    }
    
    for (auto i : v) // for each element in v
        std::cout << i << " "; // print the element
    
    std::cout << std::endl;
    return 0;
}


