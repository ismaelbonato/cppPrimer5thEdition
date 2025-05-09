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

        for (size_t i = 0; i < a1.size(); i++)
        {
            std::cout << a1[i] << ' ';
        }
        
        std::cout << std::endl;
     
    }

    {    
        std::cout << "StrBlob" << std::endl; 

        StrBlob a1;
        a1.push_back("Hello");
        a1.push_back("World");

        for (size_t i = 0; i < a1.size(); i++)
        {
            std::cout << a1[i] << ' ';
        }

        std::cout << std::endl;

        const StrBlob a2;
        a2.push_back("Hello");
        a2.push_back("World const");

        for (size_t i = 0; i < a2.size(); i++)
        {
            std::cout << a2[i] << ' ';
        }
        
        std::cout << std::endl;
    }

    {   //
        std::cout << "String" << std::endl; 

        String a1{'H', 'e', 'l', 'l', 'o', '!'};
      
        for (size_t i = 0; i < a1.size(); i++)
        {
            std::cout << a1[i];
        }
        
        std::cout << std::endl;
      
    }

    return 0;
}
