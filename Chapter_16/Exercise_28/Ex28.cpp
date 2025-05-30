#include "SharedPtr.h"
#include "UniquePtr.h"

#include <string>
#include <memory>

template<typename T>
void deleter(T *ptr)
{
    std::cout << "deleter called:" << std::endl;
    delete ptr;
}

int main()
{

    SharedPtr<std::string> ss1(new std::string("Hello World!"), deleter<std::string>);

    UniquePtr<std::string> us1 = new std::string("Hello World!");
    UniquePtr<std::string, decltype(deleter<std::string>)*> us2(new std::string("Hello World!"), deleter<std::string>);

    UniquePtr<int, decltype(deleter<int>)*> us3(new int(42), deleter<int>);

    std::cout << "us1: " << *us3 << std::endl;

    return 0;
}