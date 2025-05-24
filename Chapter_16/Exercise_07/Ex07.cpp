#include <iostream>
#include <iterator>

template<typename T, size_t N>
constexpr size_t getArrSize(T (&)[N])
{
    return N;
}

int main()
{
    int i[]{1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "{";
    for (size_t idx = 0; idx < getArrSize(i); ++idx) {
        std::cout << i[idx] << ", ";
    }
    std::cout << "}" << std::endl;

    return 0;
}