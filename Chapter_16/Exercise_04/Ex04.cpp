#include <iostream>
#include <vector>
#include <list>
#include <string>

template <typename T, typename V> T find(const T &b, const T &e, const V &value)
{
    for (auto it = b; it != e ; it++) {
        if (*it == value) return it;
    }
    return e;
}

int main()
{
    {
        std::vector<int> vec{1,2,3,4,5,6,7,8,9,0};

        auto ret = find(vec.begin(), vec.end(), 2);

        if (ret == vec.end()) std::cout << "not found" << std::endl;
        else std::cout << "number found: " << *ret << std::endl;
    }

    {
        std::list<std::string> sl{"Jan", "Feb", "Mar", "Apr", "may"};
        
        auto ret = find(sl.begin(), sl.end(), "Mar");

        if (ret == sl.end()) std::cout << "not found" << std::endl;
        else std::cout << "Word found: " << *ret << std::endl;
    }

    return 0;
}