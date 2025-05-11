#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

struct PrintString
{
public:
    PrintString(std::ostream &o) : os(o)  {};
    void operator()(const std::string &s) const
    {
        os << s << " ";
    }

private:
    std::ostream &os;
};

struct IsBiggerThan
{
private:
    std::vector<std::string>::size_type sz;
public:
    IsBiggerThan(const std::vector<std::string>::size_type sz) : sz(sz) {};
    bool operator()(const std::string &s) const 
    {
        return s.size() >= sz;
    }
};

struct IsShorter
{
    bool operator()(const std::string &a, const std::string &b) const
    {
        return a.size() < b.size();
    }
};

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

    std::stable_sort(words.begin(), words.end(), IsShorter());
    
    auto endPartition = std::partition(words.begin(), words.end(), IsBiggerThan(sz));

    auto count = endPartition - words.begin();

    std::cout << count << " "
                << make_plural(count, "word", "s")
                << " of length " << sz << " or longer" << std::endl;

    std::for_each( words.begin(), endPartition, PrintString(std::cout));
                    
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