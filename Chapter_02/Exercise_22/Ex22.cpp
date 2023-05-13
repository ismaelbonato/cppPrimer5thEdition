#include <iostream>

int main() {

    int i = 0, *p = &i;

    // This statement verifies if the pointer p has an address diferent of zero, it does not verify
    // if it's valid or invalid because it's not possible.
    if (p) {

    }
    // this statement verifies if the object pointed by p is true or false.
    if (*p) {

    }

    return 0;
}
