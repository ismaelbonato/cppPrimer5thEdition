#include <vector>
#include <iostream>

int main()
{

    std::vector<int> iVec;
    //std::vector<int> iVec;

    //std::cout << "iVec first position " << iVec.at(0) << std::endl;

    iVec.at(0) = 2;
    
    //std::cout << "iVec first position " << iVec.at(0) << std::endl;

    iVec[0] = 3;
    
    //std::cout << "iVec first position " << iVec.at(0) << std::endl;

    iVec.front() = 4;
    
    //std::cout << "iVec first position " << iVec.at(0) << std::endl;

    *(iVec.begin()) = 5;

    //std::cout << "iVec first position " << iVec.at(0) << std::endl;

    return 0;
}