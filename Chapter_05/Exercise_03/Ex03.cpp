#include <iostream>
#include <string>

bool find() {
    return false;
}

int main()
{
    int sum = 0, val = 1;
    // keep executing the while as long as val is less than or equal to 10
    while (val <= 10) 
        sum += val, ++val; // assigns sum + val to sum

    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
    std::string s{1,2,3,45,5,6,7,8};

    std::string::iterator iter = s.begin();
    while (iter != s.end()) { /* . . . */ }
    return 0;
}

