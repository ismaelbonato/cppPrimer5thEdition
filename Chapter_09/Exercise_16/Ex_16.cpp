#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::list<int> iList{1,2,3,4,5,6,7};
    std::vector<int> iVec{1,2,3,4,5,6,7};
    std::vector<int> iVec2{1,2,3};

    std::vector<int> iVecTmp(iList.begin(), iList.end());

    if (iVec == iVecTmp) {
        std::cout << "iVec1 is equal to iList" << std::endl;
    } else {
        std::cout << "iVec1 is not equal to iList" << std::endl;
    }

    if (iVec2 == iVecTmp) {
        std::cout << "iVec2 is equal to iList" << std::endl;
    } else {
        std::cout << "iVec2 is not equal to iList" << std::endl;
    }

    return 0;
}