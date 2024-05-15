
#include <iterator>
#include <vector>
#include <list>
#include <iostream>

int main()
{
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

    std::vector<int> iaVec(std::begin(ia), std::end(ia));
    std::list<int> iaList(std::begin(ia), std::end(ia));

    auto itVec = iaVec.begin();
    auto itList = iaList.begin();

    while( itVec != iaVec.end() ) {
        if (*itVec % 2) {
            itList = iaList.erase(itList);
            ++itVec;
        }   else {
            itVec = iaVec.erase(itVec);
             ++itList;
        }
    }

    std::cout << "iaVec: ";

    for (const auto number : iaVec) {
        std::cout << number << ", ";
    }
    std::cout << std::endl;

    std::cout << "iaList: ";

    for (const auto number : iaList) {
        std::cout << number << ", ";
    }
    std::cout << std::endl;

    return 0;
}


