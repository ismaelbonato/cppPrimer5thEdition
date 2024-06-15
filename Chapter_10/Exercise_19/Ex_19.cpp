#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

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
                                        [sz]
                                        (const std::string &s)
                                        {return s.size() >= sz;}
    );
    

    auto count = endPartition - words.begin();

    std::cout << count << " "
                << make_plural(count, "word", "s")
                << " of length " << sz << " or longer" << std::endl;

    std::for_each( words.begin(), 
                   endPartition,
                    [] (const std::string &s)
                    {std::cout << s << " ";}
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