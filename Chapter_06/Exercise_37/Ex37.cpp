#include <iostream>

// 1
std::string (&func(std::string (&str)[10]))[10]
{
    return str;
}

// 2 Alias
using strType = std::string(&)[10];

strType funcAlias(std::string (&str)[10])
{
    return str;
}

// 3 trailing return
auto funcAuto(std::string (&str)[10]) -> std::string(&)[10]
{
    return str;
}

// decltype --------
std::string str[10]{"A", "B", "C", "D",
                    "E", "F", "G", "H", 
                    "I", "J"};

decltype(str) &funcDecltype(std::string (&str)[10])
{
    return str;
}
// -----------------


int main ()
{
    for (auto it : str) {
        std::cout << it;
    }
    std::cout << std::endl;

    func(str)[0] = "Normal function return";

    for (auto it : func(str)) {
        std::cout << it << std::endl;
    }
    std::cout << std::endl;

    funcAlias(str)[1] = "Alias return Function";

    for (auto it : funcAlias(str)) {
        std::cout << it << std::endl;
    }
    std::cout << std::endl;

    funcAuto(str)[2] = "Trailing return Function";

    for (auto it : funcAuto(str)) {
        std::cout << it << std::endl;
    }
    std::cout << std::endl;

    funcDecltype(str)[3] = "Decltype return Function";

    for (auto it : funcDecltype(str)) {
        std::cout << it << std::endl;
    }
    std::cout << std::endl;


    return 0;
}