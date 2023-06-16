#include <iostream>
#include <vector>
#include <string>

int main ()
{
    std::vector<int> grades{0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    std::string finalGrade;
    
    for (auto grade : grades) {
        finalGrade =  ((grade > 90) ? "high pass" : 
                      (grade > 75) ) ? "pass" : 
                      (grade < 60) ? "fail" : "low pass";

        std::cout << grade << ": " << finalGrade << std::endl;
    }
    
    return 0;
}
