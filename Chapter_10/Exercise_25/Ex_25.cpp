#include <algorithm>
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
    elimDups(words);

    std::stable_partition(words.begin(),
                        words.end(), 
                        [] 
                        (const std::string &s)
                        {return true;}
    );
    
    auto endPartition = std::partition(words.begin(), words.end(), 
                                       bind(checkSize, _1, sz));
    

    auto count = endPartition - words.begin();

    std::cout << count << " "
                << make_plural(count, "word", "s")
                << " of length " << sz << " or longer" << std::endl;

    std::for_each( words.begin(), 
                   endPartition,
                    bind(printResult, _1, ref(std::cout) )
    );
                    
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