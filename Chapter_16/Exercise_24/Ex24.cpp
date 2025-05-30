#include <iostream>
#include <vector>
#include <string>
#include "Blob.h" 

int main() {

    std::vector<std::string> sVec{"Hello ", "World", "!"};
    Blob<std::string> b(sVec.begin(), sVec.end());

    for (auto it = b.begin(); it != b.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    
    return 0;
}