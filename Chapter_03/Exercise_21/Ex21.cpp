#include <iterator>
#include <ostream>
#include <string>
#include <iostream>
#include <vector>

using std::vector;
using std::string;
using std::endl;

int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    std::cout << "vector v1: sizeof= " << v1.size() << " value= ";

    for (auto it = v1.cbegin(); it != v1.cend(); it++) {
        std::cout << (*it) << " ";
    }

    std::cout << endl;

    std::cout << "vector v2: sizeof= " << v2.size() << " value= ";

    for (auto it = v2.cbegin(); it != v2.cend(); it++) {
        std::cout << (*it) << " ";
    }
    
    std::cout << endl;

    std::cout << "vector v3: sizeof= " << v3.size() << ", value= ";

    for (auto it = v3.cbegin(); it != v3.cend(); it++) {
        std::cout << (*it) << " ";
    }
    
    std::cout << endl;
    std::cout << "vector v4: sizeof= " << v4.size() << ", value= ";

    for (auto it = v4.cbegin(); it != v4.cend(); it++) {
        std::cout << (*it) << " ";
    }

    std::cout << endl;
    std::cout << "vector v5: sizeof= " << v5.size() << " value= ";

    for (auto it = v5.cbegin(); it != v5.cend(); it++) {
        std::cout << (*it) << " ";
    }
    
    std::cout << endl;

    std::cout << "vector v6: sizeof= " << v6.size() << " value= ";

    for (auto it = v6.cbegin(); it != v6.cend(); it++) {
        std::cout << (*it) << " ";
    }

    std::cout << endl;

    std::cout << "vector v7: sizeof= " << v7.size() << " value= ";
    
    for (auto it = v7.cbegin(); it != v7.cend(); it++) {
        std::cout << (*it) << " ";
    }
    
    return 0;
}