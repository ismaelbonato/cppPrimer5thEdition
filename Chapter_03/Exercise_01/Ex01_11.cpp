#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int begin, end;
    cin >> begin >> end;

    cout << "first value: "<< begin << " second value: " << end << endl;


    while (begin <= end) {
        cout << "Number: " << begin << endl;
        ++begin;
    }

    return 0;
}
