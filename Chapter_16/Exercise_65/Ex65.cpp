#include <iostream>
#include <string>
#include <sstream>


template<typename T>
std::string debug_rep(const T &s)
{
    std::cout << "debug_rep(const T &s)" << std::endl;
    std::stringstream ret;
    ret << s;
    return ret.str();
}

template<typename T>
std::string debug_rep(T *s)
{
    std::cout << "debug_rep(const T *s)" << std::endl;
    
    if (!s) {
        return std::string("invalid");
    }  
    
    return debug_rep(*s);
}

template<>
std::string debug_rep(char *p)
{
    return debug_rep(std::string(p));
}
template<>
std::string debug_rep(const char *p)
{
    return debug_rep(std::string(p));
}

int main()
{
    std::string s1("Hello World!");
    std::string *sp(new std::string(s1));

    char c[]{'h','e','l','l','o',' ' ,'W','o','r','l','d','!'};
    char cp[] = "Hello World!";

    std::cout << debug_rep(s1) << std::endl;
    std::cout << debug_rep(sp) << std::endl;
    std::cout << debug_rep(c) << std::endl;
    std::cout << debug_rep(cp) << std::endl;
    
    return 0;
}