#include <iostream>
#include <string>

int main()
{
    std::string str1, str2;

    do {
        std::cout << "write a first string: "; 
        std::cin >> str1;
        std::cout << "write a second string: "; 
        std::cin >> str2;

        if (str1 < str2) {
            std::cout << "the first string is less than second:" << std::endl; 
        } else if (str1 > str2) {
            std::cout << "the second string is less than first:" << std::endl; 
        } else {
            std::cout << "The strings are equal:" << std::endl; 
        }
        
    } while (true);

    return 0;
}