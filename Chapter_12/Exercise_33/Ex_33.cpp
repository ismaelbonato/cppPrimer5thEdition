#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include "TextQuery.h"


void runQueries(std::ifstream &infile)
{
    TextQuery tq(infile); 

    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        // stop if we hit end-of-file on the input or if a 'q' is entered
        if (!(std::cin >> s) || s == "q") break;
        // run the query and print the results
        print(std::cout, tq.query(s)) << std::endl;
    }  
}

int main()
{
    std::ifstream file("input");
    runQueries(file);

    return 0;
}
