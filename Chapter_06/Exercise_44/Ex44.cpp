#include <iostream>
#include <string>

// compare the length of two strings
inline bool isShorter(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size();
}

int main ()
{   
    std::cout << "man is shorter than woman? " << (isShorter("man", "woman") ? true : false) << std::endl;

    return 0;
}