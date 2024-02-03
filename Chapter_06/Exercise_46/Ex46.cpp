#include <iostream>
#include <string>

// compare the length of two strings
constexpr bool isShorter(const std::string &s1, const std::string &s2)
{
    return (s1.size() < s2.size());
}

int main ()
{   
    std::string ss1("man"), ss2("woman");
    bool ret = isShorter(ss1, ss2);
    std::cout << "man is shorter than woman? " << ( ret ? true : false) << std::endl;

    return 0;
}
