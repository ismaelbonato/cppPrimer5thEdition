#include <iostream>
#include <vector>
#include <string>
#include "Blob.h" 

int main() {

    Blob<std::string> a1;
    a1.push_back("Hello");
    a1.push_back("World");
    a1.push_back("!");

    for (auto it = a1.begin(); it != a1.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    
    return 0;
}