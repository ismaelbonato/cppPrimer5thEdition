#include <iostream>

template <typename T> int compare(const T& a, const T& b)
{
    if (a < b) return -1;
    if (a > b) return 1;

    return 0;
}

template <typename T> void printAnswer(const T& n)
{
    if (n > 0) std::cout << "The first is greater than the second!" << std::endl;
    else if (n < 0) std::cout << "The first is less than the second! " << std::endl;
    else std::cout << "The first is equal to the second! " << std::endl;
}

int main()
{
    std::cout << "write 2 numbers separated by space" << std::endl; 
    int a, b;
    
    while (std::cin >> a >> b)
    {
        printAnswer(compare(a,b));
    }
    
    return 0;
}