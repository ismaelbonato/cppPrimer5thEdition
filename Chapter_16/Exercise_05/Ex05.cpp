#include <array>
#include <iostream>

template <typename T, size_t N> void print(const T (&arr)[N])
{
    for (auto elem : arr) std::cout << elem;
    std::cout << std::endl;
}

int main()
{
    const char c[]{'f','i','r','s','t', ' ', 't','e','s','t'};

    print(c);

    int i[]{1,2,3,4,5,6,7,8,9,0}; 

    print(i);

    return 0;
}