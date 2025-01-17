#include <iostream>
#include <memory>
#include <string>

const int n = 42;

int main()
{
    std::allocator<std::string> alloc;

    auto const p = alloc.allocate(n);
    std::string *q = p; 
    std::string s;

    while ((std::cin >> s) && (q != (p + n))) {
        alloc.construct(q++, s);
    }

    
    while (q != p) {
        alloc.destroy(--q); 
    }
    
    alloc.deallocate(p, n);

    return 0;
}