#include "String.h"
#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "StrVec.h"
#include <vector>

int main()
{     
    {
        std::cout << "StrVec" << std::endl; 
        
        StrVec a1;
        a1.push_back("Hello");
        a1.push_back("World");

        StrVec a2;
        a2.push_back("Hello");
        a2.push_back("World");

        std::cout << "a1 < a2 = " << (a1 < a2) << std::endl; 
        std::cout << "a1 > a2 = " << (a1 > a2) << std::endl; 
        std::cout << "a1 >= a2 = " << (a1 >= a2) << std::endl; 
        std::cout << "a1 <= a2 = " << (a1 <= a2) << std::endl;
    }

    {    
        std::cout << "StrBlob" << std::endl; 

        StrBlob a1;
        a1.push_back("Hello");
        a1.push_back("World");

        StrBlob a2;
        a2.push_back("Hello");
        a2.push_back("World");

        std::cout << "a1 < a2 = " << (a1 < a2) << std::endl; 
        std::cout << "a1 > a2 = " << (a1 > a2) << std::endl; 
        std::cout << "a1 >= a2 = " << (a1 >= a2) << std::endl;
        std::cout << "a1 <= a2 = " << (a1 <= a2) << std::endl; 
    }

    {   //
        std::cout << "String" << std::endl; 

        String a1{'H', 'e', 'l', 'l', 'o', '!'};
        String a2{'H', 'e', 'l', 'l', 'o', '!'};
        
        std::cout << "a1 < a2 = " << (a1 < a2) << std::endl;  
        std::cout << "a1 > a2 = " << (a1 > a2) << std::endl;  
        std::cout << "a1 >= a2 = " << (a1 >= a2) << std::endl;
        std::cout << "a1 <= a2 = " << (a1 <= a2) << std::endl;
    }

    return 0;
}
