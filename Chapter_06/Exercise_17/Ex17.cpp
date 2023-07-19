#include <iostream>
#include <string>

bool isThereCapitalLetter(const std::string &str) 
{
    for (auto ch : str) {
        if (isupper(ch)) {
            return true;
        }
    }

    return false;
}

void setLowerCase(std::string &str) {
    for (auto &ch : str) {
        ch = std::tolower(ch);
    }

}

int main ()
{
    std::string str{"qwerasdfzxcV"};

    std::cout << str << std::endl;

    if (isThereCapitalLetter(str)) {
        std::cout << "There is a capital letter" << std::endl;

        setLowerCase(str);
    } else {
        std::cout << "There is not such thing as capital letter" << std::endl;
    }

    std::cout << str << std::endl;

    return 0;
}
