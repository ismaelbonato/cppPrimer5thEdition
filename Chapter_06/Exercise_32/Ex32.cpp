#include <iostream>

int &get(int *arry, int index) 
{ 
    return arry[index]; 
}

int main() 
{
    int ia[10];
    
    for (auto idx : ia) {
        std::cout << idx << ' ' << std::endl;
    }
    
    for (int i = 0; i != 10; ++i) {
        get(ia, i) = i;
    }

    for (auto idx : ia) {
        std::cout << idx << ' ' << std::endl;
    }

}