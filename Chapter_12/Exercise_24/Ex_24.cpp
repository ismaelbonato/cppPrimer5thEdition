#include <cstdio>
#include <iostream>
#include <string>

const int MAXLENGH = 20;
 
int main()
{
    char *c(new char[MAXLENGH + 1]());

    std::cin.getline(c, MAXLENGH); // the program 

    std::cout.write(c, MAXLENGH);
    std::cout.write("\n", 3);

    delete [] c;


    return 0;
}