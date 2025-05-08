#include "String.h"
#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "StrVec.h"
#include <vector>

int main()
{     
    {
        StrVec vec1;
        vec1.push_back("Hello");
        vec1.push_back("World");

        StrVec vec2;
        vec2.push_back("C++");
        vec2.push_back("Programming");

        if (vec2 == vec1) {
            std::cout << "vec2 is equal to vec1" << std::endl;
        } else {
            std::cout << "vec2 and vec1 are different" << std::endl;
        }

        vec1 = vec2;

        if (vec2 == vec1) {
            std::cout << "vec2 is equal to vec1" << std::endl;
        } else {
            std::cout << "vec2 and vec1 are different" << std::endl;
        }
    }

    {
        StrBlob b1({"Hello"});
        StrBlob b2({"World"});
        
        if (b1 == b2) {
            std::cout << "b1 is equal to b2" << std::endl;
        } else {
            std::cout << "b1 and b2 are different" << std::endl;
        }

        b1 = b2;

        if (b1 == b2) {
            std::cout << "b1 is equal to b2" << std::endl;
        } else {
            std::cout << "b1 and b2 are different" << std::endl;
        }    
    }

    {   //String
        String s1{'H', 'e', 'l', 'l', 'o', '!'};
        String s2{'H', 'e', 'l', 'l', 'o', '!'};

        if (s1 == s2) {
            std::cout << "s1 is equal to s2" << std::endl;
        } else {
            std::cout << "s1 and s2 are different" << std::endl;
        }

    }

    return 0;
}
