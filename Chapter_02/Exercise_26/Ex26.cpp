#include <iostream>

// 2.26: Which of the following are legal? For those that are illegal, explain why.

int main() {

    //(a)
    // It's illegal, because const needs to be initialized.
    const int buf;

    // (b)
    // it's legal
    int cnt = 0;

    //(c)
    // it's legal
    const int sz = cnt;

    //(d)
    // ++cnt is legal
    // ++sz is illegal, you cannot change the value of a const
    ++cnt; ++sz;

    return 0;
}
