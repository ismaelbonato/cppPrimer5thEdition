#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <array>

std::string &replace(std::string &s, 
                    const std::string &oldVal, 
                    const std::string &newVal)
{
    for (auto idx = 0; idx <= s.size(); ++idx) {
        if(s.substr(idx, oldVal.size()) == oldVal)  {
            s.replace(idx, oldVal.size(), newVal);
        }
    }
    return s;
}

int main()
{
    std::string s("asdf zxcv tho, tho test thru tho");

    std::cout << "old String s = " << s << std::endl;

    replace(s, "tho", "though");
    replace(s, "thru", "through");

    std::cout << "new String s = " << s << std::endl;

    return 0;
}