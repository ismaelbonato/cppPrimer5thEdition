#include <iostream>


template<typename T, typename... Args>
std::ostream &print(std::ostream &os, const T arg, const Args&... rest)
{
    os << arg << ", ";
    return  print(os, rest...);
}

template<typename T>
std::ostream &print(std::ostream &os, const T &arg)
{
    return os << arg;
}

int main()
{
    print(std::cout, 1,2,3,4,5,6,7,8, 9) << std::endl;
    print(std::cout, 1,2.0,'3', "Hello", "World", "!") << std::endl;

    return 0;
}