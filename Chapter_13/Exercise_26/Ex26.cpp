#include "StrBlob.h"
#include <iostream>

int main ()
{

    StrBlob b1;
    std::cout << "size of b1 before: " << b1.size() << std::endl;

    {
        StrBlob b2{"a", "an", "the"};

        std::cout << "size of b2 before: " << b2.size() << std::endl;
        StrBlob b3(b2);

        std::cout << "size of b3 before: " << b3.size() << std::endl;

        b1 = b2;
        std::cout << "size of b1 b1 = b2: " << b1.size() << std::endl;

        b2.push_back("about");
        std::cout << "size of b1 b2.push_back(): " << b1.size() << std::endl;
        std::cout << "size of b2 b2.push_back(): " << b2.size() << std::endl;

        b3.push_back("another");
        b3.push_back("test");
        b3.push_back("test");


        std::cout << "size of b3: " << b3.size() << std::endl;

    }

    std::cout << "size of b1 ending: " << b1.size() << std::endl; 


    return 0;
}