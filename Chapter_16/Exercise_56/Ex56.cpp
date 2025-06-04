#include <iostream>
#include <sstream>

template<typename T>
std::string debugRep(const T& t)
{
    std::stringstream ss;
    ss << t; 
    return ss.str();
}

template<typename T>
std::ostream &print(std::ostream &os, const T &arg)
{
    return os << arg;
}

template<typename T, typename... Args>
std::ostream &print(std::ostream &os, const T arg, const Args&... rest)
{
    os << arg << ", ";
    return  print(os, rest...);
}

template<typename... Args>
std::ostream &errorMsg(std::ostream &os, const Args&... rest)
{
    return print(os, debugRep(rest)...);
}

int main()
{
    errorMsg(std::cout, 1,2,3,4,5,6,7,8, 9) << std::endl;
    errorMsg(std::cout, 1,2.0,'3', "Hello", "World", "!") << std::endl;

    return 0;
}