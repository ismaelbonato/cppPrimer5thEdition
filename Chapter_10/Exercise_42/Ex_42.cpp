#include <algorithm>
#include <iostream>
#include <string>
#include <list>

void elimDups(std::list<std::string> &words)
{
    words.sort();
    words.unique();
}

int main ()
{
    std::list<std::string> sList{"the", "quick", "red", 
                                        "fox", "jumps", "over",
                                         "the", "slow", "red",
                                         "turtle"};

    elimDups(sList);


    for (auto word : sList) {
        std::cout << word << " ";
    }

    std::cout << std::endl;

    return 0;
}