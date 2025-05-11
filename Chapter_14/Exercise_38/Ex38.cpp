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

    auto count = std::count_if(words.begin(), words.end(), TestBound(1, 10));

    std::cout << "count: " << count << std::endl;

    return 0;
}