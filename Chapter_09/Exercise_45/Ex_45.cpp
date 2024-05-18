#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <array>

const std::string insertPrefixSufix(const std::string &name, 
                    const std::string &prefix, 
                    const std::string &sufix)
{
    auto newName = name;
    
    auto it = newName.begin();
    
    newName.insert(it, prefix.begin(), prefix.end());
    
    newName.append(sufix);
    
    return newName;
}

int main()
{
    std::cout << "Old Name = Jhon" << std::endl;

    const std::string newName = insertPrefixSufix("jhon Dooo",
                                                "Mr. ",
                                                " Jr.");

    std::cout << "New Name = " << newName << std::endl;

    return 0;
}