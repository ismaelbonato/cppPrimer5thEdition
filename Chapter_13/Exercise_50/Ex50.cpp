#include "String.h"
#include <vector>

int main()
{     
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