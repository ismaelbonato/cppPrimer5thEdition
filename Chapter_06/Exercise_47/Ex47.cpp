#include <vector>
#include <iostream>

//#define NDEBUG

// in order to pass vec by value you need to pass an index due the fact
// vec is a copy and vec.end() will return end of the copy address 
void recVectorPrinter(const std::vector<int> vec, const std::vector<int>::size_type idx)
{
#ifndef NDEBUG
    std::cerr << " : in function " << __func__
        << " at line " << __LINE__ << std::endl
        << " idx = "<< idx  << std::endl
        << " iVec[" << idx << "] = " << vec[idx - 1] << std::endl;

#endif

    if (idx < vec.size()) {
        std::cout << "value: " << vec[idx] << std::endl;
        recVectorPrinter(vec, idx + 1);
    }
}

int main()
{

#ifndef NDEBUG
    std::cerr << "File: " << __FILE__
        << " Compiled on " << __DATE__ << std::endl;
#endif
    
    std::vector<int> iVec{1,2,3,4,5,6,7,8,9};
    
    std::cout << "Passing the Vector by value and the index" << std::endl;
    recVectorPrinter(iVec, 0);



    return 0;
}