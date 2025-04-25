#include <iostream>
#include <string>

class HasPtr
{
public:
    HasPtr(const std::string &s = std::string())
        : ps(new std::string(s))
        , i(0){};

    ~HasPtr() { delete ps; };

    HasPtr(const HasPtr &origin)
        : ps(new std::string(*(origin.ps)))
        , i(origin.i){};

    HasPtr &operator=(const HasPtr &origin)
    {
        if (this == &origin) {
            return *this; // Handle self-assignment by
        }

        i = origin.i;

        delete (ps);
        ps = new std::string(*(origin.ps));

        return *this;
    };

    inline void swap(HasPtr &lhs, HasPtr &rhs)
    {
        std::cout << "swap(HasPtr &lhs, HasPtr &rhs)" << std::endl; 
        using std::swap;
        swap(lhs.ps, rhs.ps);
        swap(lhs.i, rhs.i);
    };
    

private:
    std::string *ps;
    int i;
};

int main()
{
    HasPtr p1("Hello");
    HasPtr p2(p1);
    HasPtr p3;

    p3 = p1;

    p1.swap(p2, p3);

    return 0;
}