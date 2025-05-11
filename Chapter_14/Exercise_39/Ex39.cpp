#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class TestBound
{
private:
    std::size_t lBound;
    std::size_t rBound;

public:
    TestBound(const std::size_t l, const std::size_t r)
        : lBound(l)
        , rBound(r){};

    bool operator()(const std::string &s) const
    {
        return (s.size() >= lBound) && (s.size() <= rBound);
    }
};

int main()
{
    std::vector<std::string> words;
    std::string word;

    std::ifstream file("input");
    if (!file) {
        std::cerr << "error opening file" << std::endl;
        return -1;
    }

    while (file >> word) {
        words.push_back(word);
    }

    auto count1 = std::count_if(words.begin(), words.end(), TestBound(1, 9));
    auto count2 = std::count_if(words.begin(), words.end(), TestBound(10, 100));

    std::cout << "Words of size 1 through 9: " << count1 << std::endl;
    std::cout << "Words of size 10 or more: " << count2 << std::endl;

    return 0;
}