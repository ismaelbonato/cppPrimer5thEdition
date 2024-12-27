#include <memory>
#include <iostream>

void process(std::shared_ptr<int> sp)
{
    std::cout << "is sp is also unique()? " << std::boolalpha << sp.unique() << std::endl;
    std::cout << "sp use count: " << sp.use_count() << std::endl;
}


int main()
{

    std::shared_ptr<int> p(new int(42));
    
    std::cout << "is p unique()? " << std::boolalpha << p.unique() << std::endl;
    process(p);

    std::cout << "is p is also unique()? " << std::boolalpha << p.unique() << std::endl;
    std::cout << "p use count: " << p.use_count() << std::endl;

    return 0;
}