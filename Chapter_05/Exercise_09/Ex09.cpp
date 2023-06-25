#include <iostream>

int main () 
{
    unsigned char ch;
    unsigned int aCount = 0,
                eCount = 0,
                iCount = 0,
                oCount = 0,
                uCount = 0,
                nonVowel = 0;

    while (std::cin >> ch) {
        switch (ch) {
            case 'a':
                ++aCount;
                break;
            case 'e':
                ++eCount;
                break;
            case 'i':
                ++iCount;
                break;
            case 'o':
                ++oCount;
                break;
            case 'u':
                ++uCount;
                break;
            default:
                ++nonVowel;
                break;
        }
    }

    std::cout << "Number of a: " << aCount << std::endl; 
    std::cout << "Number of e: " << eCount << std::endl;
    std::cout << "Number of i: " << iCount << std::endl;
    std::cout << "Number of o: " << oCount << std::endl;
    std::cout << "Number of u: " << uCount << std::endl;
    std::cout << "Number of non Vowel: " << nonVowel << std::endl;

    return 0;
}