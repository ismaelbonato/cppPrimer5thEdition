#include <iostream>
#include <string>
#include <vector>

#define SUM  0
#define SUB  1
#define MULT 2
#define DIV  3

int func(const int x, const int y);

int funcSum(const int x, const int y) {
    return x + y;
}

int funcSub(const int x, const int y) {
    return x - y;
}

int funcMult(const int x, const int y) {
    return x * y;
}

int funcDiv(const int x, const int y) {
    return x / y;
}

int main ()
{   
    std::vector<decltype(func) *> pVec{funcSum, 
                                        funcSub, 
                                        funcMult, 
                                        funcDiv};

    std::cout << "result of 5 + 5 is: " << pVec[SUM](5, 5) << std::endl;
    std::cout << "result of 5 - 5 is: " << pVec[SUB](5, 5) << std::endl;
    std::cout << "result of 5 * 5 is: " << pVec[MULT](5, 5) << std::endl;
    std::cout << "result of 5 / 5 is: " << pVec[DIV](5, 5) << std::endl;

    return 0;
}