#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

template<typename T>
size_t count(const T &t, const typename T::value_type &u)
{
    return std::count(t.begin(), t.end(), u);
}

template<>
size_t count(const std::vector<const char *> &t,
             const std::vector<const char *>::value_type &u)
{
    std::cout << "using specialized version of count" << std::endl;
    return std::count(t.begin(), t.end(), u);
}

int main()
{
    std::vector<int> iVec{1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6};
    std::vector<double> dVec{
        1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};

    std::vector<std::string>
        sVec{"1", "2", "3", "4", "5", "6", "7", "8", "9", "1", "2", "3", "4", "5", "6"};

    std::cout << "count iVec: " << count(iVec, 2) << std::endl;
    std::cout << "count dVec: " << count(dVec, 3.0) << std::endl;
    std::cout << "count sVec: " << count(sVec, "7") << std::endl;

    std::list<int> iList{1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6};
    std::cout << "count iList: " << count(iList, 7) << std::endl;

    std::vector<const char *>
        vcc{"1", "2", "3", "4", "5", "6", "7", "8", "9", "1", "2", "3", "4", "5", "6"};

    const char *p{"5"};

    std::cout << "count vcc: " << count(vcc, p) << std::endl;

    return 0;
}