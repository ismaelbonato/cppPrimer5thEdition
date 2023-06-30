#include <cstddef>
#include <vector>
#include <iostream>

int main ()
{
    std::vector<int> ivec1{0, 1, 1, 3};
    std::vector<int> ivec2{0, 1, 1, 3};
    
    auto it1 = ivec1.begin();
    auto it2 = ivec2.begin();

    for (/* null */; 
            ((it1 != ivec1.end()) || (it2 != ivec2.end())) 
                && (*it1 == *it2); 
            ++it1, ++it2 ) {/* ... */}

    if ( ivec1.size() < ivec2.size() ) {
        if ((it1 == ivec1.end())) {
            std::cout << "vector 1 is a prefix of vector 2" << std::endl;
            return 1;
        } 
        std::cout << "vector 1 is not a prefix of vector 2" << std::endl;
    } else if (ivec1.size() > ivec2.size() ) {
        if ((it2 == ivec2.end())) {
            std::cout << "vector 2 is a prefix of vector 1" << std::endl;
            return 1;
        }
        std::cout << "vector 2 is not a prefix of vector 1" << std::endl;
    } else {
        if (it1 == ivec1.end()) {
            std::cout << "vector 1 and 2 are prefix" << std::endl;
            return 1;
        }
    } 

    return 0;
}