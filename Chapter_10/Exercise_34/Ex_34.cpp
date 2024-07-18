#include <iterator>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main ()
{
    std::vector<std::string> sVec{"1", "2" ,"3", "4", "5" };

    std::for_each(sVec.crbegin(), sVec.crend(), 
                                []
                                (const std::string &s)
                                {std::cout << s << ",";}
    );

    std::cout << std::endl;

    return 0;
}