#include <iostream>

int main () 
{
    unsigned char ch, oldCh =  '\0';
    unsigned int ffCount = 0,
                    flCount = 0,
                    fiCount = 0;

    while (std::cin >> std::noskipws >> ch) {
        switch (oldCh) {
            case 'f':
                switch (ch) {
                    case 'f':
                        ++ffCount;
                        break;
                    case 'l':
                        ++flCount;
                        break;
                    case 'i':
                        ++fiCount;
                        break;
                }
                break;
            default:
                break;
        }
        oldCh = ch;
    }

    std::cout << "Number of ff: " << ffCount << std::endl; 
    std::cout << "Number of fl: " << flCount << std::endl;
    std::cout << "Number of fi: " << fiCount << std::endl;
    return 0;
}