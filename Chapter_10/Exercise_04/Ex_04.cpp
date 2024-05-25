#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main ()
{
    std::vector<double> iVec {1.1,2.2, 3.2};

    auto sum = std::accumulate(iVec.cbegin(),iVec.cend(),  0);

    std::cout << "The sum of the vector is: " << sum << std::endl;

    return 0;
}