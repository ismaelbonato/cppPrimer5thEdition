#include <iostream>
#include <type_traits>

template<typename T, typename D>
auto sum(const T &x, const D &y) -> typename std::common_type<T, D>::type
{
    return x + y;
}

int main()
{
    std::cout << sum(5,5) << std::endl;

    return 0;
}