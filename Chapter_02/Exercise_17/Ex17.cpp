#include <iostream>

int main() {

    int i, &ri = i;

    // i = 5
    i = 5;

    // i = 10
    ri = 10;

    // It will print 10 10
    std::cout << i << " " << ri << std::endl;

    return 0;
}
