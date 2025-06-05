#include <iostream>
#include <memory>
#include <string>

template<typename T,typename... Args>
inline typename std::shared_ptr<T> make_shared(Args&&... args)
{
    std::allocator<T> alloc;
    return std::allocate_shared<T>(alloc, args...);
}

int main()
{
    std::shared_ptr<std::string> sp = make_shared<std::string>("Hello World!");

    std::cout << *sp << std::endl;
    return 0;
}