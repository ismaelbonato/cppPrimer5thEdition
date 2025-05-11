#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std::placeholders;

int main()
{
    {
        std::vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::size_t number = 100;

        // Count version
        auto ret = count_if(
            vi.begin(),
            vi.end(),
            std::bind(std::modulus<int>(), number, _1)
        );

        auto amountOfDivNumbers = vi.size() - ret;

        std::cout << "Amount of divisible numbers: " << amountOfDivNumbers << std::endl;

        // --------------------------------------------------------------------
        std::set<int> divisibleList;
        std::modulus<int> modulus;

        std::binary_negate<std::modulus<int>> nModulus (modulus);

        // List of divisible numbers
        auto res = std::copy_if(
            vi.begin(), 
            vi.end(), 
            std::inserter(divisibleList, divisibleList.end()),
            std::bind(nModulus, number, _1)
        );
    
        std::cout << number << " is divisible by: ";

        for (auto i : divisibleList) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}