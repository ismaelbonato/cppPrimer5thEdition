#include <iostream>
#include <vector>
#include <string>
#include "StrBlobPtr.h" 

class HasStrBlobPtr
{
    friend class StrBlobPtr;
public:
    HasStrBlobPtr(StrBlobPtr &sb) : strBlobPtr(&sb) {};

    StrBlobPtr *operator->() const
    {
        return strBlobPtr;
    }
    HasStrBlobPtr &operator++()
    {
        ++(*strBlobPtr);
        return *this;
    }

private:
    StrBlobPtr *strBlobPtr;
};


int main() {

    StrBlob a1;
    a1.push_back("Hello");
    a1.push_back("World");
    a1.push_back("!");

    auto ret = a1.begin();

    HasStrBlobPtr hasStrBlobPtr{ret};

    std::cout << hasStrBlobPtr->operator*() << std::endl;
    ++hasStrBlobPtr;
    std::cout << hasStrBlobPtr->operator*() << std::endl;
    ++hasStrBlobPtr;
    std::cout << hasStrBlobPtr->operator*() << std::endl;

    return 0;
}