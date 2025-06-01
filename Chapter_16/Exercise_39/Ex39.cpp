#include <string>
#include <iostream>

template <typename T>
int compare(const T &v1, const T &v2)
{
    std::cout << "V1: " << v1 << " V2: " << v2 << std::endl;
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

int main()
{
    // with the same size;
    compare("Hello", "World");
    compare<const char*>("Hello", "World");
    compare<const char[sizeof("hello")]>("Hello", "World");
    compare<std::string>("Hello", "World");

    // different sizes.
    //compare("Hello World", "!"); error const char[6] and const char[1] does not match.
    compare<const char*>("Hello World", "!");
    compare<std::string>("Hello World", "!");

    return 0;
}