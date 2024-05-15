#include <forward_list>
#include <vector>
#include <list>
#include <iostream>

int main()
{   
    std::vector<int> v{1,2,3,4,5,6,6,7,8,9};
    auto begin = v.begin();

    while (begin != v.end()) {
        ++begin; 
//      begin = v.insert(begin, 42); 
        v.insert(begin, 42); 
        ++begin;
    }
    return 0;
}