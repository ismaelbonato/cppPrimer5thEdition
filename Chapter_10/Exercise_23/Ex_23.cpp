#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <functional>

using namespace std::placeholders;

bool checkSize (const int &i, std::string::size_type sz) 
{
    return (i > sz);
}

std::vector<int>::const_iterator findElementBySize (const std::vector<int> &i, 
                                            std::string::size_type sz) 
{
    return std::find_if(i.begin(), i.end(), bind(checkSize, _1, sz) );
}

int main ()
{
    const std::vector<int> iVec{1, 2, 3, 4, 5, 6, 7, 8};
    std::string s("four");

    auto it = findElementBySize(iVec, s.size());

    if (it != iVec.end()) {
        std::cout << "Value found = " << *it << std::endl;
    } else {
        std::cout << "Value not found" << std::endl;
    }

    return 0;
}