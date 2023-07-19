#include <iostream>
#include <string>

void swap(int &xValue, int &yValue)
{
    int tmp = xValue;

    xValue = yValue;
    yValue = tmp;
}

// returns the index of the first occurrence of c in s
// the reference parameter occurs counts how often c occurs
std::string::size_type find_char(const std::string &s, 
                            char c,
                            std::string::size_type &occurs)
{
    auto ret = s.size(); // position of the first occurrence, if any
    occurs = 0; // set the occurrence count parameter
    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size())
                ret = i; // remember the first occurrence of c
            ++occurs; // increment the occurrence count
        }
    }
    return ret; // count is returned implicitly in occurs
}

int main()
{
    int x = 42, y = 1;

    std::cout << "x, y = " << x << ", " << y << std::endl;

    swap(x, y);

    std::cout << "the result of swapped: " << x << ", " << y << std::endl;
    

    std::string::size_type z;
    std::string m;
    find_char(m, 'a', x);


    return 0;
}


