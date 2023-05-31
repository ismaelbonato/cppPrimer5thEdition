#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int sum = 0, val = 50;
    // keep executing the while as long as val is less than or equal to 100
    while (val <= 100) {
        sum += val; // assigns sum + val to sum
        ++val; // add 1 to val
    }
    cout << "Sum of 50 to 100 inclusive is "
    << sum << endl;


    return 0;
}
