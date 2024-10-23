#include <map>
#include <string>
#include <iostream>
#include <vector>

int main()
{
    using MappedValue = std::map<std::string, size_t>; 
    
    MappedValue mapped;

    MappedValue::mapped_type mappedValue = mapped["Answer"] = 42;

    std::cout << mappedValue << std::endl;


    return 0;
}