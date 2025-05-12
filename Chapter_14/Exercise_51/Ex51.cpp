#include <iostream>

struct LongDouble {
    LongDouble(double val = 0.0) : x(val) {}
    operator double() {return x;}
    operator float() {return static_cast<float>(x);}

private:
    double x;
};

void calc(int a) 
{
    std::cout << "cal int " << a << std::endl;
}
void calc(LongDouble &a)
{
    std::cout << "cal LongDouble " << static_cast<double>(a) << std::endl;
}

int main()
{
    double dval = 0.0;
    LongDouble ldval;

    calc(dval);
    calc(ldval);

    

    return 0;
}