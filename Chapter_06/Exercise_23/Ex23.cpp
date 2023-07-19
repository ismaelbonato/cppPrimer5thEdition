#include <cstddef>
#include <iostream>


void printWithDelimiter(const int *beg, int delimiter)
{    
    while(*beg != delimiter) {
        std::cout << *beg++;
    }
    std::cout << std::endl;
}

void print(const int *beg, const int * end)
{    
    while(beg != end) {
        std::cout << *beg++;
    }
    std::cout << std::endl;
}

void print(const int *arr, std::size_t size)
{    
    for (decltype(size) idx = 0; idx < size; ++idx) {
        std::cout << *(arr+idx);
    }
    std::cout << std::endl;
}

void print(const int (&arr)[2])
{    
    for (auto item : arr) {
        std::cout << item;
    }
    std::cout << std::endl;
}

void print(const int *value)
{
    std::cout << *value << std::endl;
}


int main ()
{
    int i = 0; 
    int j[2] = {0, 1};
    int jCopy[3] = {0, 1, -1};

    printWithDelimiter(jCopy, -1);
    print(std::begin(j), std::end(j));
    print(j, std::end(j) - std::begin(j));
    print(j);
    print(&j[0]);


    // ----------------------
    print(&i);

    return 0;
}