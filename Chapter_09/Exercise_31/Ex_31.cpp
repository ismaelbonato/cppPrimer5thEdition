#include <forward_list>
#include <vector>
#include <list>
#include <iostream>

int main()
{
    std::forward_list<int> vi = {0, 1, 2,3,4,5,6,7,8,9};
    auto prev = vi.before_begin();
    auto iter = vi.begin(); 

    while (iter != vi.end()) {
        if ((*iter % 2)) {
            iter = vi.insert_after(prev, *iter++);
            
            prev = iter;
            ++iter;
            ++iter;
            ++prev;
        } else {
            iter = vi.erase_after(prev);            
        }
    }

    for (auto number : vi) {
        std::cout << number << ", ";
    }
    std::cout << std::endl;

    return 0;
}