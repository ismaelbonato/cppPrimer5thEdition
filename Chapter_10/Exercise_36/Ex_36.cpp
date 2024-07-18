#include <iterator>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main ()
{
    std::vector<int> iVec{0, 2, 0, 4, 0, 1, 0, 2 };

    auto lastZero = std::find(iVec.crbegin(), iVec.crend(), 0);

    std::cout << "the last zero is placed in the " 
                <<  lastZero.base() - iVec.begin() 
                << "th position" 
                <<  std::endl;

    return 0;       
}



