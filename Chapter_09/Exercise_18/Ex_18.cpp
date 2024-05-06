#include <iostream>
#include <vector>
#include <deque>
#include <string>

int main()
{


    std::deque<std::string> sDeque;
    std::string tmp;


    while (std::cin >> tmp ) {
        sDeque.push_back(tmp);
    }

    std::cout << "Printing sDeque" << std::endl;

    for (auto begin = sDeque.begin(); begin != sDeque.end(); ++begin) {
        std::cout << *begin << std::endl;
    }

    return 0;
}