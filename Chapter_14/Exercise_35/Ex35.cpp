#include <iostream>
#include <sstream>

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
        
        return  s;
    }
private:
    std::istream &i;

};


int main ()
{
    std::stringstream i("This is a line");
    
    PrintString ps(i);

    auto ret = ps();

    std::cout << ret << std::endl;


    return 0;
}