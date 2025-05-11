#include <iostream>


class IfThenElse
{

public:
    int operator()(int a, int b, int c) const
    {
        return (a ? b : c);
    }

private:
};

int main ()
{
    IfThenElse ifThenElse;

    auto ret = ifThenElse(1,2,3);

    std::cout << "result of ifThenElse: "<< ret << std::endl;

    return 0;
}