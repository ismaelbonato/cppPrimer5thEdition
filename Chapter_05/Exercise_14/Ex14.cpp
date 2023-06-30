#include <iostream>

int main () 
{
    std::string oldWord, word, resWord;
    unsigned int count = 1, resCount = 0;

    while (std::cin >> word) {
        if (oldWord == word) {
            ++count;
        } else {
            count = 1;
        }

        if (count > resCount) {
            resWord = oldWord;
            resCount = count;
        }

        oldWord = word;
    }

    if (resCount > 1) {
        std::cout << resWord << " ocurred " << resCount << "times" << std::endl;
    } else {
        std::cout << "no word was repeated" << std::endl;
    }

    return 0;
}