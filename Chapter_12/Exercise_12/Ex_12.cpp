#include <iostream>
#include <memory>

void process(std::shared_ptr<int> sp)
{
    std::cout << "is sp is also unique()? " << std::boolalpha << sp.unique() << std::endl;
    std::cout << "sp use count: " << sp.use_count() << std::endl;
}

int main()
{
    auto p = new int();
    auto sp = std::make_shared<int>();
    
    process(sp);
    process(new int());
    process(p);
    process(std::shared_ptr<int>(p));


    return 0;
}