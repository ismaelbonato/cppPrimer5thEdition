#include <iostream>
#include <vector>
#include <string>

int main ()
{
    std::vector<int> grades{0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    std::string finalGrade;
    
    for (auto grade : grades) {      
        if (grade > 90) {
            finalGrade = "high pass";
        } else if (grade > 75) {
            finalGrade = "pass";
        } else if (grade > 60) {
            finalGrade = "low pass";
        } else {
            finalGrade = "fail";
        }

        std::cout << grade << ": " << finalGrade << std::endl;
    }
     
    return 0;
}
