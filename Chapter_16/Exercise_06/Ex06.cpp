#include <iostream>
#include <iterator>

template<typename T, size_t N>
T *begin(T (&arr)[N])
{
    return arr;
}

template<typename T, size_t N>
T *end(T (&arr)[N])
{
    return arr + N;
}

int main()
{
    int i[]{1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "{";
    for (auto it = begin(i); it != end(i); it++) {
        std::cout << *it << ", ";
    }
    std::cout << "}" << std::endl;

    return 0;
}