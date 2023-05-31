#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int val = 10;
    while (val >= 0) {
        cout << "Number: " << val << endl;
        --val;
    }

    return 0;
}
