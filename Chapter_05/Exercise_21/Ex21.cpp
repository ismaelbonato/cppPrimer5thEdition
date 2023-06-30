#include <iostream>
#include <string>

int main ()
{
    std::string word, oldWord;


    while (std::cin >> word) {
        if (word[0]  > 'a' && word[0] < 'z') // you can use also isupper();
            continue;

        if (oldWord == word) {
            break;
        }
        oldWord = word;
    }   

    if (oldWord == word) {
        std::cout << word << std::endl;
    } else {
        std::cout << "no word was repeated" << std::endl;
    }

    return 0;
}