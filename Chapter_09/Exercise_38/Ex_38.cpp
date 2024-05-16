#include <iostream>
#include <vector>
#include <array>


int main()
{
    std::array<int, 8> aInt{0,1,2,3,4,5,6,7};
    std::vector<std::array<int,8> > aVec;

    for (int idx = 0;  idx <= 9 ; ++idx) {
        aVec.push_back(aInt);

        std::cout << "aVec.size(): " << aVec.size() << std::endl;
        std::cout << "aVec.capacity(): " << aVec.capacity() << std::endl;
    }



    return 0;
}