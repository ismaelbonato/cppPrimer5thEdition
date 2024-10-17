#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

int main (void)
{

    std::vector<std::string> excludedWords;

    std::cout << "ctrl + d to print" << std::endl;
    std::cout << "enter a word" << std::endl;

    std::string word;

    while (std::cin >> word) {
        auto ret = std::find(excludedWords.begin(),
                                 excludedWords.end(),
                                  word);
    
        if(ret == excludedWords.end()) {
            excludedWords.push_back(word);
        }
    }
    
    std::cout << "Saved words:" << std::endl;

    std::for_each(excludedWords.begin(), excludedWords.end(), []
                                                            (const std::string w)
                                                            {std::cout << w << std::endl;});


    return 0;
}