#include <algorithm>
#include <iostream>
#include <vector>

class IsEqualTo
{
public:
    IsEqualTo(int v) : value(v){};

    bool operator()(int a) const { return (a == value); }

private:
    int value;
};

int main()
{
    std::vector<int> iv{1, 2, 3, 1, 2, 3, 1, 2, 3};

    std::replace_if(iv.begin(), iv.end(), IsEqualTo(2), 0);

    std::cout << '{';
 
    for (auto i : iv) {
        std::cout << i << ',';
    }
    
    std::cout << '}' << std::endl;

    return 0;
}