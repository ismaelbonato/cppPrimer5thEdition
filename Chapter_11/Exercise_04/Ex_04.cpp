#include <map>
#include <string>
#include <iostream>
#include <set>
#include <cctype>
#include <algorithm>
#include <vector>

int main()
{
    // count the number of times each word occurs in the input
    std::map<std::string, std::string::size_type> word_count;
    std::set<std::string> exclude = {};

    std::string word;
    while (std::cin >> word) {
        for (auto &ch: word) {
            ch = std::tolower(ch);
        }

        auto oneLastPunctuation = std::remove_if(word.begin(), 
                                                word.end(), 
                                                [] (const char ch) 
                                                { return std::ispunct(ch); }
                                                );

        word.erase(oneLastPunctuation, word.end());

        if (exclude.find(word) == exclude.end())
            ++word_count[std::string(word.begin(), word.end())];
    }    

    for (const auto &w : word_count) 
        std::cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << std::endl;
    
    return 0;
}