#include <iostream>
#include <string>
#include <vector>

int main () {

    std::vector<std::string> scores = {"F", "D", "C", "B", "A", "A++"};
    std::string letterGrade;
    unsigned int grade = 45;
    
    (grade < 60) ? letterGrade = scores[0] : 
                letterGrade = scores[(grade/10) - (scores.size() -1)]; 

    std::cout << letterGrade << std::endl;


    int ival = 6;
    if (ival)
        cout << "ival = " << ival << endl;
    else
        cout << "ival = 0\n";


    return 0;
}