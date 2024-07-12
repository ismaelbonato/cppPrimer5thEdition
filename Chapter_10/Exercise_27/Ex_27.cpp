#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <deque>

int main ()
{
    std::vector<int> i{ 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> iV;
    std::list<int> iL;
    std::deque<int> iD;

    std::copy(i.begin(), i.end(), std::back_inserter(iV));
    std::copy(i.begin(), i.end(), std::inserter(iL, iL.begin()));
    std::copy(i.begin(), i.end(), std::front_inserter(iD));


    std::for_each(iV.begin(), iV.end(), 
                        [] (int &v) 
                        { std::cout << v << ", "; });

    std::cout << std::endl;

    std::for_each(iL.begin(), iL.end(), 
                        [] (int &v) 
                        { std::cout << v << ", "; });

    std::cout << std::endl;

    std::for_each(iD.begin(), iD.end(), 
                        [] (int &v) 
                        { std::cout << v << ", "; });

    std::cout << std::endl;

    return 0;
}