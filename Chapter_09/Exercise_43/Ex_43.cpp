#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <array>

std::string &replace(std::string &s, 
                    const std::string &oldVal, 
                    const std::string &newVal)
{
    auto it = s.begin();
    
    while(it <= (s.end() - oldVal.size())) {
        auto strTmp= std::string{it, it + oldVal.size()};
        
        if(strTmp == oldVal)  {
            it = s.erase(it, it + oldVal.size());
            it = s.insert(it, newVal.begin(), newVal.end() );
            it = it + newVal.size();
        }
        ++it;
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