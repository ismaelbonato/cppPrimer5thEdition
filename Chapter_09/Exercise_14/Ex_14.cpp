#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<const char *> cVec{"aa", 
                                    "asdf", 
                                    "asdfg"};
    std::vector<std::string> sVec;

    sVec.assign(cVec.begin(), cVec.end());

    for (auto content : sVec) {
        std::cout << content << std::endl;
    }

    return 0;
}