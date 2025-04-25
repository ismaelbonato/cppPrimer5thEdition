#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class HasPtr
{
public:
    HasPtr(const std::string &s = std::string())
        : ps(new std::string(s))
        , i(0){};

    ~HasPtr() 
    { 
        delete ps; 
        std::cout << "~HasPtr()" << std::endl; 
    };

    HasPtr(const HasPtr &origin)
        : ps(new std::string(*(origin.ps)))
        , i(origin.i){};

    HasPtr &operator=(HasPtr rhs)
    {
        if (this == &rhs) {
            return *this; // Handle self-assignment by
        }

        swap(*this, rhs);
        return *this;
    };

    bool operator<(const HasPtr& rhs) 
    {
        return *ps < *(rhs.ps);
    }

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
    std::vector<HasPtr> hasPtrList{{"4"}, {"3"}, {"2"}, {"1"}};

    std::sort(hasPtrList.begin(), hasPtrList.end());

    return 0;
}