#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec{1,2,3,4,5,6,7,8,9,0};
    std::vector<int>::size_type cnt = ivec.size();

    for(std::vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt++) {
        std::cout << (ivec[ix] = cnt) << std::endl; 

    }

    return 0;
}