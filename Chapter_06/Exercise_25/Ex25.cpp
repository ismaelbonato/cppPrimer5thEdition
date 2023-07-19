#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string s1;

    if (argc > 2) {
        s1 = argv[1];
        s1.append(argv[2]);

        std::cout << s1 << std::endl;
    } else {
        std::cout << "to few arguments." << std::endl;
    }
    

    return 0;
}