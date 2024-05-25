#include <iostream>
#include <list>
#include <algorithm>

int main ()
{
    std::list<std::string> sList {"1","2", "3", "2"};

    std::cout << "The number appears "
        << std::count(sList.cbegin(), 
                        sList.cend(), 
                        "2") 
        << " times in the list"<< std::endl;


    return 0;
}