#include <iostream>
#include <string>

class HasPtr
{
public:
    HasPtr() = default;
    HasPtr(const std::string &s = std::string())
        : ps(new std::string(s))
        , i(0)
        , userCount(new std::size_t(1))
    {
        std::cout << "userCount: " << *userCount << std::endl;
    };

    HasPtr(const HasPtr &origin)
        : ps(origin.ps)
        , i(origin.i)
        , userCount(origin.userCount)
    {
        ++(*userCount);
        std::cout << "HasPtr(const HasPtr &origin)" << std::endl;
    };

    HasPtr &operator=(const HasPtr &rhs)
    {
        std::cout << " HasPtr & operator=(const HasPtr &rhs)" << std::endl;

        --(*userCount);
        std::cout << "old userCount: " << *userCount << std::endl;

        if (*userCount == 0) {
            delete ps;
            delete userCount;
        }

        ++(*rhs.userCount);
        userCount = rhs.userCount;

        std::cout << "New userCount: " << *userCount << std::endl;

        i = rhs.i;
        ps = rhs.ps;

        return *this;
    };

    ~HasPtr()
    {
        --(*userCount);
        std::cout << " ~HasPtr userCount: " << *userCount << std::endl;

        if (*userCount == 0) {
            delete ps;
            delete userCount;
        }
    };

    std::string *ps;
    int i;
    std::size_t *userCount;
};

int main()
{
    HasPtr hasPtr1("ABCDEF");
    HasPtr hasPtr2("HIJLNK");

    HasPtr hasPtr1cp1(hasPtr1);
    HasPtr hasPtr1cp2(hasPtr1);
    HasPtr hasPtr1cp3(hasPtr1);

    HasPtr hasPtr2cp1(hasPtr2);
    HasPtr hasPtr2cp2(hasPtr2);

    hasPtr1cp2 = hasPtr2cp2;

    return 0;
}