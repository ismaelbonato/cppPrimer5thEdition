#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

int main()
{   // First Version c-style.
    const char *c1 = "Hello";
    const char *c2 = "World!";
    auto sz = strlen(c1) + strlen(c2) + 1;

    char *cp(new char[sz]);

    std::snprintf(cp, sz, "%s %s", c1, c2);

    std::printf("First exercise: %.*s\n",static_cast<int>(sz) ,cp);
    //std::cout << "First exercise: " << cp << std::endl; 
    delete [] cp;
    // Second Version std::string;
    std::string s1("Hello");
    std::string s2("World!");
    
    std::string *sp = new std::string(s1 + ' ' + s2);

    std::cout << "Second exercise " << sp << std::endl;

    delete sp;

    return 0;
}