#include <forward_list>
#include <iostream>

using strList = std::forward_list<std::string>;

void findAndReplace(strList &list, 
                    const std::string str1, 
                    const std::string str2)
{
    auto curr = list.begin(); 
    auto prev = curr;

    while (curr != list.end()) { 
        if (*curr == str1) {
            curr = list.insert_after(curr, str2);
            return;
        } else {
            prev = curr;
            ++curr; 
        }
    }

    curr = list.insert_after(prev, str2);
}


int main()
{
   
   strList sList{"banana",
                    "apple",
                    "kiwi",
                    "orange",
                    "mellon",
                    "water mellon"};
   

    std::cout << "List of fruits: ";
    for (auto value : sList) {
        std::cout << value << ", ";
    }
    std::cout << std::endl;

    findAndReplace(sList, "orange", "strawberry");

    std::cout << "List of fruits: ";
    for (auto value : sList) {
        std::cout << value << ", ";
    }
    std::cout << std::endl;


}