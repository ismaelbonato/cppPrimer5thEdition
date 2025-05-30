#include <iostream>
#include <list>
#include <string>
#include <vector>

template<typename T>
std::ostream &print(std::ostream &os, const T &container)
{
    for (typename T::size_type idx = 0; idx < container.size(); idx++) {
        os << container.at(idx);
    }

    return os;
}

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::string s{'a', 'b', 'c', 'd', 'd', 'f'};
    //std::list<int> l{1,2,3,4,5,6,7,8,9,0};

    print(std::cout, v) << std::endl;
    //print(std::cout, l) << std::endl;
    print(std::cout, s) << std::endl;

    return 0;
}