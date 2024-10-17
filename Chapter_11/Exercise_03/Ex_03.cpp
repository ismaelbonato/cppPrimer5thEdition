#include <map>
#include <string>
#include <iostream>

int main()
{
    // count the number of times each word occurs in the input
    std::map<std::string, std::string::size_type> word_count; // empty map from string to size_t

    std::string word;
    while (std::cin >> word) {
        ++word_count[word];
    }    

    for (const auto &w : word_count) // for each element in the map
        std::cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << std::endl;
    
    return 0;
}