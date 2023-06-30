#include <iostream>

int main () 
{
    unsigned char ch;
    unsigned int aCount = 0,
                eCount = 0,
                iCount = 0,
                oCount = 0,
                uCount = 0,
                nonVowel = 0,
                spaceCount = 0,
                tabCount = 0,
                nfCount = 0;

    while (std::cin >> std::noskipws >> ch) {
        switch (ch) {
            case 'a': case 'A':
                ++aCount;
                break;
            case 'e': case 'E':
                ++eCount;
                break;
            case 'i': case 'I':
                ++iCount;
                break;
            case 'o': case 'O':
                ++oCount;
                break;
            case 'u': case 'U':
                ++uCount;
                break;
            case ' ':
                ++spaceCount;
                break;
            case '\t':
                ++tabCount;
                break;     
            case '\n':
                ++nfCount;
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
    std::cout << "Number of spaces: " << spaceCount << std::endl;
    std::cout << "Number of tabs: " << tabCount << std::endl;
    std::cout << "Number of new lines: " << nfCount << std::endl;
    std::cout << "Number of non Vowel: " << nonVowel << std::endl;

    return 0;
}