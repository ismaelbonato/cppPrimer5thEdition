#include <iostream>
#include <sstream>
#include <vector>

class PrintString
{
public:
    PrintString(std::istream &is = std::cin) : i(is) {};

    std::string operator()() const
    {
        std::string s;
        if (std::getline(i, s)) {
            return s;
        }
        
        return s;
    }
private:
    std::istream &i;
};


int main ()
{
    std::stringstream i;
    std::vector<std::string> sv;
    
    i << "This is the line 1" << std::endl;
    i << "This is the line 2" << std::endl;
    i << "This is a line" << std::endl;

    PrintString ps(i);

    std::string ret;

    while(ret = ps(), !ret.empty()) {
        sv.push_back(ret);
    }

    for (auto s : sv) {
        std::cout << s << std::endl;
    }
    

    return 0;
}