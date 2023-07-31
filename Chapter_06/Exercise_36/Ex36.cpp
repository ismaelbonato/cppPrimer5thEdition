#include <iostream>

std::string (&func(std::string (&str)[10]))[10]
{
    return str;
}

int main ()
{
    std::string str[10]{"A", "B"};

    for (auto it : str) {
        std::cout << it << std::endl;
    }

    func(str)[0] = "reference returned is LValue";

    for (auto it : str) {
        std::cout << it << std::endl;
    }

    return 0;
}