#include <iostream>
#include <vector>
#include <string>

int main ()
{
    std::vector<int> iVec{0, 1, 2, 3, 4, 5};

    for (auto &it : iVec) {
        it = ( it % 2 ? it * 2 : it );    
        std::cout <<  it << ' ';
    }

    std::cout << std::endl;

    return 0;
}
