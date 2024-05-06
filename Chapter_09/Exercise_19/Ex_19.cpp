#include <iostream>
#include <list>
#include <string>

int main()
{


    std::list<std::string> sList;
    std::string tmp;


    while (std::cin >> tmp ) {
        sList.push_back(tmp);
    }

    std::cout << "Printing sList" << std::endl;

    for (auto begin = sList.begin(); begin != sList.end(); ++begin) {
        std::cout << *begin << std::endl;
    }

    return 0;
}