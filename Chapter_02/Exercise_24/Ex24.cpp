#include <iostream>


int main() {

    int i = 42;
    // It's legal because void* has a type Unknown and can hold any other type,
    // but it's use is limited.
    void *p = &i;

    // It's ilegal because can only hold an object of the same type,
    //long *lp = &i;

    return 0;
}
