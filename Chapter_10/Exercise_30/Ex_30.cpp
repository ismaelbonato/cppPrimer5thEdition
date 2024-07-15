#include <algorithm>
#include <iostream>
#include <istream>
#include <vector>
#include <iterator>

int main ()
{
    std::istream_iterator<int> int_it(std::cin), eof;
    std::ostream_iterator<int> int_int_out(std::cout, ",");
    
    std::vector<int> iVec(int_it, eof);

    std::sort(iVec.begin(), iVec.end());

    std::copy(iVec.begin(), iVec.end(), int_int_out);

    std::cout << std::endl;

    return 0;
}