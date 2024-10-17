#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main (void)
{
    using pr = std::pair<std::string, int>;

    std::vector<pr> vP;

    std::string word;
    int value;

    while (std::cin >> word >> value ) {
        vP.emplace_back(word, value);
    }

    std::for_each(vP.begin(), vP.end(), []
                    (std::pair<std::string, int> p)
                    {std::cout << p.first << " " << p.second << std::endl;}    
    );
  
    return 0;
}