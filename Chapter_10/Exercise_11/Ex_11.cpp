#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void elimDups(std::vector<std::string> &words)
{
    std::sort(words.begin(),words.end());
    
    auto endUnique = std::unique(words.begin(),words.end());

    words.erase(endUnique, words.end());
}

bool isShorter(const std::string &str1, const std::string &str2)
{
    return str1.size() < str2.size();
}

int main ()
{
    std::vector<std::string> sVec{"the", "quick", "red", 
                                        "fox", "jumps", "over",
                                         "the", "slow", "red",
                                         "turtle"};

    elimDups(sVec);

    std::stable_sort(sVec.begin(), sVec.end(), isShorter);

    for (auto word : sVec) {
        std::cout << word << " ";
    }

    std::cout << std::endl;

    return 0;
}