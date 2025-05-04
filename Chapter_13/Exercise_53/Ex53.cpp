#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <chrono>

class HasPtr
{
public:
    HasPtr(const std::string &s = std::string())
        : ps(new std::string(s))
        , i(0)
    {
        std::cout << "HasPtr(const std::string &s = std::string())" << std::endl;
    }

    ~HasPtr()
    {
        if (ps) {
            delete ps;
        }
        std::cout << "~HasPtr()" << std::endl;
    };

    HasPtr(const HasPtr &origin)
        : ps(new std::string(*(origin.ps)))
        , i(origin.i)
    {
        std::cout << "HasPtr(const HasPtr &origin)" << std::endl;  
    }

    HasPtr &operator=(HasPtr &rhs)
    {
       //std::cout << "HasPtr &operator=(HasPtr &rhs)" << std::endl;
        if (this == &rhs) {
            return *this; 
        }
        delete(ps);
        
        i = rhs.i;
        ps = rhs.ps;

        rhs.ps = nullptr;
        
        return *this;
    }

    HasPtr &operator=(HasPtr &&rhs) noexcept
    {
        if (this == &rhs) {
            return *this;
        }

        //std::cout << "HasPtr &operator=(HasPtr &&origin)" << std::endl;
        using std::swap;
        swap(ps, rhs.ps);
        i = rhs.i;

        return *this;
    }

    bool operator<(const HasPtr &rhs) { return *ps < *(rhs.ps); }

    inline void swap(HasPtr &lhs, HasPtr &rhs)
    {
        std::cout << "swap(HasPtr &lhs, HasPtr &rhs)" << std::endl;
        using std::swap;
        swap(lhs.ps, rhs.ps);
        swap(lhs.i, rhs.i);
    }

private:
    std::string *ps;
    int i;
};

int main()
{

    HasPtr hp{"Hellow World 1!"};
    HasPtr hp2{"Hellow World 2!"};

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::nanoseconds;

    auto t1 = high_resolution_clock::now();
    hp = hp2; 
    auto t2 = high_resolution_clock::now();
    hp = std::move(hp2);
    auto t3 = high_resolution_clock::now();

    /* Getting number of milliseconds as an integer. */
    auto timeCopy = duration_cast<nanoseconds>(t2 - t1);
    auto timeMove = duration_cast<nanoseconds>(t3 - t2);
    /* Getting number of milliseconds as a double. */

    std::cout << "hp = hp2; takes " << timeCopy.count() << " nanoseconds to run" << std::endl;
    std::cout << "hp = std::move(hp2); takes " << timeMove.count() << " nanoseconds to run" << std::endl;

    return 0;
}