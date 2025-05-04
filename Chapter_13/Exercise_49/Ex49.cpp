#include "String.h"
#include "Message.h"
#include "StrVec.h"
#include <vector>

int main()
{
    { // Message class
        Message msg1("Hello");
        Message msg2("World");

        Folder folder1;
        Folder folder2;

        msg1.save(folder1);
        msg2.save(folder2);

        swap(msg1, msg2);

        folder1 = folder2;
    }

    { // StrVec
        StrVec vec{{"Hello"}, {"World"}, {"C++"}};

        for (auto it = vec.begin(); it != vec.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
     
    {   //String
        std::vector<String> sVec;
        sVec.reserve(4);

        sVec.push_back(String{{'H'}, {'e'}, {'l'}, {'l'}, {'o'}, {'!'}});
        sVec.push_back(String{{'H'}, {'e'}, {'l'}, {'l'}, {'o'}, {'!'}});
        sVec.push_back(String{{'H'}, {'e'}, {'l'}, {'l'}, {'o'}, {'!'}});
        sVec.push_back(String{{'H'}, {'e'}, {'l'}, {'l'}, {'o'}, {'!'}});
    }

    return 0;
}