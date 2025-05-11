#include <functional>
#include <string>
#include <map>
#include <iostream>

int add(const int &a, const int &b) {return a + b;}

struct Mod
{
    int operator()(const int &a, const int &b) const
    {
        return a % b;
    }
};

int main()
{
    std::function<int(const int, const int)> minus{std::minus<const int>()};
    std::function<int(const int, const int)> multiply{[](const int a, const int b) {return a * b;}};
    auto div = [](const int &a, const int &b) {return a / b;};


    std::map<std::string, std::function<int(const int, const int)> > functionTable{
        {"+", add},
        {"-", minus},
        {"*", multiply}
    };

    functionTable.insert({"/", div});
    functionTable.insert({"%", Mod()});


    std::cout << "2 + 2 = "<< functionTable["+"](2,2) << std::endl; 
    std::cout << "2 - 2 = "<< functionTable["-"](2,2) << std::endl; 
    std::cout << "2 * 2 = "<< functionTable["*"](2,2) << std::endl; 
    std::cout << "2 / 2 = "<< functionTable["/"](2,2) << std::endl; 
    std::cout << "2 % 2 = "<< functionTable["%"](2,2) << std::endl; 

    return 0;
}