#include <iostream>
#include <string>
#include <vector>

int func(const int x, const int y);

int main ()
{   
    std::vector<decltype(func) *> pVec;

    pVec.push_back(func);
    pVec.push_back(func);

    return 0;
}