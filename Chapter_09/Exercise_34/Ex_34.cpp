
#include <forward_list>
#include <vector>
#include <list>
#include <iostream>

int main()
{   
    std::vector<int> vi{1,2,3,4,5,6,6,7,8,9};

    auto iter = vi.begin();
    while (iter != vi.end()) {
        if (*iter % 2) {
            iter = vi.insert(iter, *iter);
        }
        ++iter;
    }
    
    return 0;
}


