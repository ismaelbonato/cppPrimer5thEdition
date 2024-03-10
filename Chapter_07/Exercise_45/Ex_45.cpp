#include <vector>
#include <iostream>

struct NoDefault {
    NoDefault(int x): i(x) {};
    int i;
};

struct C {
    C() = default;
    NoDefault noDefault;
};

int main()
{
    std::vector<C> vec(10);

    return 0;
}