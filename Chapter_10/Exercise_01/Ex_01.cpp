#include <iostream>
#include <vector>
#include <algorithm>

int main ()
{
    std::vector<int> iVec {1,2,3,5,2};


    std::cout << "The number appears "
        << std::count(iVec.cbegin(), iVec.cend(), 6) 
        << " times in the vector"<< std::endl;


    return 0;
}