#include <iostream>

// d
// Invalid: a variable cannot begin with an undescore out of the function scope.
int _;


int main() {

    // a
    // Invalid: Identifier double is keywork of the language
    int double = 3.14;

    // b
    // Valid: but it's useless without any indication of it's meaning.
    // it's not consistent with the convension.
    int _;

    // c
    // Invalid: catch is a keyword of the language
    int catch-22;

    // d
    // Invalid: Indentifiers cannot begin with a number.
    int 1_or_2 = 1;

    // e
    // Valid: it's not consistent with the convension.
    double Double = 3.14;


    return 0;
}
