#include <algorithm>
#include <iostream>
#include <vector>



std::vector<int> * createVector()
{
    return new std::vector<int>;
}

void deleteVector(std::vector<int> *v) 
{
    delete v;
}


void printVector(std::vector<int> *v)
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

    deleteVector(v);

    return 0;
}