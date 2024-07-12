#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <list>


int main ()
{
    std::vector<int> iV{ 1, 2, 3, 4, 5, 5, 4, 3, 2, 1};

    std::list<int> iL;

    std::sort(iV.begin(), iV.end());

    auto inserter_it = std::back_inserter(iL);

    std::unique_copy(iV.begin(), iV.end(), inserter_it);

    std::for_each(iL.begin(), iL.end(), 
                        [] (int &v) 
                        { std::cout << v << ", "; });

    std::cout << std::endl;

    return 0;
}