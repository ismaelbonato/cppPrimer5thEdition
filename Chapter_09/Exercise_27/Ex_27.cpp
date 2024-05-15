#include <forward_list>
#include <iostream>


int main()
{
    std::forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};
    
    auto prev = flst.before_begin(); 
    auto curr = flst.begin(); 
    
    std::cout << "List of numbers: ";
    for (auto value : flst) {
        std::cout << value << ", ";
    }
    std::cout << std::endl;

    while (curr != flst.end()) { 
        if (*curr % 2) 
            curr = flst.erase_after(prev);
        else {
            prev = curr; 
            ++curr; 
        }
    }

    std::cout << "Odd numbers removed: ";
    for (auto value : flst) {
        std::cout << value << ", ";
    }
    std::cout << std::endl;


}