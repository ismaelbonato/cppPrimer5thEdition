#include <iostream>
#include <vector>

int main()
{
    std::vector<int> iVec1{1,2,3,4,5,6,7};
    std::vector<int> iVec2{1,2,3,4,5,6,7};
    std::vector<int> iVec3{1,2,3,4,5};

    if (iVec1 == iVec2) {
        std::cout << "iVec1 is equal to iVec2" << std::endl;
    } else {
        std::cout << "iVec1 is not equal to iVec2" << std::endl;
    }

    if (iVec1 == iVec3) {
        std::cout << "iVec1 is equal to iVec3" << std::endl;
    } else {
        std::cout << "iVec1 is not equal to iVec3" << std::endl;
    }

    return 0;
}