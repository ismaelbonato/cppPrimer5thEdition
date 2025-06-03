#include <iostream>
#include <utility>
#include <functional>

void g(int && t1, int & t2)
{
    std::cout << t1 << " " << t2 << std::endl;
}

template<typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2)
{
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

int main()
{
    int j = 42;

    flip(g, j, 42);

    return 0;
}