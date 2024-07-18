#include <iterator>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main ()
{
    std::vector<std::string> sVec{"1", "2" ,"3", "4", "5" };

    for (auto it = std::prev(sVec.end()); it != std::prev(sVec.begin()); --it) {
        std::cout << *it << ",";
    }

    std::cout << std::endl;


    return 0;       
}



