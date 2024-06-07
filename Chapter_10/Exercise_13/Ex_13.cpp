

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool hasFiveChar(const std::string &s)
{
    return (s.size() >= 5);
}

int main()
{
    std::vector<std::string> sVec{"Lorem",
                                     "ipsum",
                                     "dolor",
                                     "sit" ,
                                     "amet", 
                                     "ipsum", 
                                     "proident", 
                                     "dolore", 
                                     "et", 
                                     "deserunt", 
                                     "consequat"};


    const auto last = std::partition(sVec.begin(), sVec.end(), hasFiveChar);

    for (auto b = sVec.begin(); b != last; ++b) {
        std::cout << *b << std::endl;
    }

    return 0;
}