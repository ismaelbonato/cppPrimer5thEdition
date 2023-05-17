#include <iostream>

int main()
{
// ----------------- Exercise 1.09 --------------------
    std::cout << "// Exercise 1.9:" << std::endl;
    int sum = 0;
    for (int i = 50; i <= 100; ++i)
        sum += i;

    std::cout << "sum is " << sum << std::endl;
// ---------------------- End -------------------------

// ----------------- Exercise 1.10 --------------------
    std::cout << "// Exercise 1.10:" << std::endl;
    for (int i = 10; i >= 0; --i)
        std::cout << "Number " << i << std::endl;
// ---------------------- End -------------------------

// ----------------- Exercise 1.11 --------------------
    std::cout << "// Exercise 1.11:" << std::endl;
    int begin, end;
    std::cin >> begin >> end;
    for (int i = begin; i <= end; ++i)
        std::cout << "Number  " << i << std::endl;
// ---------------------- End -------------------------

    return 0;
}


