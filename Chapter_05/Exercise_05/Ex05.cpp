#include <iostream>
#include <string>
#include <vector>

int main () {

    std::vector<std::string> scores = {"F", "D", "C", "B", "A", "A++"};
    std::string letterGrade;
    unsigned int grade = 69;
    
    if (grade < 60) {
        letterGrade = scores[0];
    } else {
        letterGrade = scores[(grade/10) - (scores.size() -1)]; 
    }

    std::cout << letterGrade << std::endl;

    return 0;
}