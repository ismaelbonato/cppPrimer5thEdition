#include <cstddef>
#include <iostream>
#include <string>


void swapperByPointerToPointer(const int **x, const int **y)
{
    const int *tmp = *x;

    *x = *y;
    *y = tmp;
}

void swapperByRef(const int* &x, const int* &y ) 
{
    const int *tmp = x;

    x = y;
    y = tmp;

}

void print(const int (&ia)[10])
{
    for (size_t i = 0; i != (sizeof(ia)/sizeof(ia[0])); ++i)
    std::cout << ia[i] << std::endl;
}

int main ()
{
    const int x = 1;
    const int y = 2;
    const int *px = &x;
    const int *py = &y;

    const int arr[10] = {0,1,2,3,4,5,6,7,8,9};

    print(arr);

    std::cout << "*px = " << *px << ", *py = " << *py << std::endl;
    std::cout << "px = " << px << ", py = " << py << std::endl;

    //swapperByPointerToPointer(&px, &py);
    swapperByRef(px, py);
    std::cout << "*px = " << *px << ", *py = " << *py << std::endl;
    std::cout << "px = " << px << ", py = " << py << std::endl;

    return 0;
}
