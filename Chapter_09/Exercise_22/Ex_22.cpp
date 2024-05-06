#include <vector>
#include <iostream>


int main()
{
    std::vector<int> iv{1,2,3,4,5,6,7,8,9,10};
    std::vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;

    int some_val = 4;

    while (iter != mid) {
        if (*iter == some_val) {
            iter = iv.insert(iter, 2 * some_val);
            mid = iv.begin() + iv.size()/2;
            iter++;
        }
        ++iter;
    }

    for (auto number : iv) {
        std::cout << number << ", "; 
    }

    std::cout << std::endl;

    return 0;
}