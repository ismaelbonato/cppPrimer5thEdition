#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std::placeholders;

int main()
{
    { // (a) Count the number of values that are greater than 1024
        std::vector<int> vi{1024, 1030, 8000, 90, 10, 1100, 12, 1300, 4000, 40, 4};
        std::size_t limit = 1024;

        // first version
        auto ret = count_if(
            vi.begin(), 
            vi.end(), 
            [limit](const std::size_t &i) {
                return std::greater<int>()(i, limit);
            }
        );

        // bind version
        ret = count_if(
            vi.begin(),
            vi.end(),
            std::bind(std::greater<int>(), _1, limit)
        );

        std::cout << "Number greater than 1024: " << ret << std::endl;
    }

    { // b Find the first string that is not equal to pooh
        std::vector<std::string> sv{"pooh", "pooh", "pppp", "pooh","poh"};
        std::string field{"pooh"};

        auto retIt = std::find_if(
            sv.begin(), 
            sv.end(),
            [&field](const std::string &s) { 
                return std::not_equal_to<std::string>()(s, field);
            }
        );

        retIt = std::find_if(
            sv.begin(), 
            sv.end(),
            std::bind(std::not_equal_to<std::string>(), _1, field)
        );
    
        std::cout << "The first string not equal to pooh is: " << *retIt << std::endl;
    }

    { // Multiply all values by 2
        std::vector<int> si{1,2,3,4,5,6,7,8,9,};
        unsigned int multiplier = 2;

        std::for_each(
            si.begin(), 
            si.end(),
            [multiplier] (int &i) {
                i = std::multiplies<int>()(i, multiplier); 
            }
        );

        std::transform(
            si.begin(), 
            si.end(), 
            si.begin(),
            [multiplier] (const int &i) {
                return std::multiplies<int>()(i, multiplier);
            }
        );

        std::transform(
            si.begin(), 
            si.end(), 
            si.begin(),
            std::bind(std::multiplies<int>(), _1, multiplier)
        );

        std::cout << '{';
        for (auto i : si) {
            std::cout << i << ',';
        }
        std::cout << '}' << std::endl;
    }
    
    return 0;
}