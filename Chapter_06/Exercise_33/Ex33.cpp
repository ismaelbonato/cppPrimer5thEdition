#include <vector>
#include <iostream>

// in order to pass vec by value you need to pass an index due the fact
// vec is a copy and vec.end() will return end of the copy address 
void recVectorPrinter(const std::vector<int> vec, std::vector<int>::size_type idx)
{
    if (idx < vec.size()) {
        std::cout << "value: " << vec[idx] << std::endl;
        recVectorPrinter(vec, idx + 1);
    }
}

void recVectorPrinter(const std::vector<int> &vec, std::vector<int>::iterator it)
{
    if (it != vec.end()) {
        std::cout << "value: " << *it << std::endl;
        recVectorPrinter(vec, it + 1);
    }
}

void recItVectorPrinter(std::vector<int>::iterator begin, const std::vector<int>::iterator end)
{
    if (begin != end) {
        std::cout << "value: " << *begin << std::endl;
        recItVectorPrinter(begin + 1, end);
    }
}

int main()
{
    std::vector<int> iVec{1,2,3,4,5,6,7,8,9};
    
    std::cout << "Passing the Vector by value and the index" << std::endl;
    recVectorPrinter(iVec, 0);
    std::cout << "Using reference to and vector and its iterator" << std::endl;
    recVectorPrinter(iVec, iVec.begin());
    std::cout << "Using the iterator begin and end" << std::endl;
    recItVectorPrinter(iVec.begin(), iVec.end());

    return 0;
}