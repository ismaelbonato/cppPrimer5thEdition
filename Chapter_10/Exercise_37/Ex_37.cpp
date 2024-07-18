#include <iterator>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

int main ()
{
    std::vector<int> iVec{0, 1, 2, 3, 4, 5,
                             6, 7, 8, 9 };

    std::list<int> iList(iVec.crbegin() + 3, iVec.crend() - 2);

    std::for_each(iList.begin(), iList.end(), 
                                                []
                                                (const int &i)
                                                {std::cout << i << ",";}
    );

    std::cout << std::endl;

    return 0;       
}



