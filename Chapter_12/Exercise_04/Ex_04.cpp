#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

using SharedVector = std::shared_ptr<std::vector<int>>;

SharedVector createVector()
{
    return std::make_shared<std::vector<int>>();
}

void printVector(SharedVector v)
{
    std::for_each(v->begin(),v->end(), 
        []
        (int value)
        {std::cout << value << std::endl;});
}


int main ()
{
    auto v = createVector();

    v->push_back(1);
    v->push_back(2);
    v->push_back(3);
    v->push_back(4);
    v->push_back(5);
    
    printVector(v);

    return 0;
}