#include <algorithm>
#include <ostream>
#include <string>
#include <vector>
#include <iostream>
#include <functional>

using namespace std::placeholders;

// return the plural version of word if ctr is greater than 1
std::string make_plural(size_t ctr, 
                    const std::string &word, 
                    const std::string &ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

void elimDups(std::vector<std::string> &words)
{
    std::sort(words.begin(),words.end());
    
    auto endUnique = std::unique(words.begin(),words.end());

    words.erase(endUnique, words.end());
}

bool checkSize (const std::string &s, std::vector<std::string>::size_type sz) {
    return (s.size() >= sz);

}

void printResult(const std::string &s, std::ostream &os ) 
{
    os << s << " ";
}

void biggies(std::vector<std::string> &words, 
                std::vector<std::string>::size_type sz)
{

    auto checkSizeEx = bind(checkSize, _1, sz);
    auto printResultEx = bind(printResult, _1, ref(std::cout));

    elimDups(words);

    std::stable_sort(words.begin(),
                        words.end(), 
                        [] 
                        (const std::string &a, const std::string &b)
                        {return a.size() < b.size();}
    );
    
    auto endFindIf = std::find_if(words.begin(), 
                                        words.end(), 
                                        checkSizeEx);

    auto count = words.end() - endFindIf;

    std::cout << count << " "
                << make_plural(count, "word", "s")
                << " of length " << sz << " or longer" << std::endl;

    std::for_each(endFindIf, 
                    words.end(),
                    printResultEx);
                    
    std::cout << std::endl;
}

int main ()
{
    std::vector<std::string> sVec{"the", "quick", "red", 
                                        "fox", "jumps", "over",
                                         "the", "slow", "red",
                                         "turtle"};


    biggies(sVec, 4);

    return 0;
}