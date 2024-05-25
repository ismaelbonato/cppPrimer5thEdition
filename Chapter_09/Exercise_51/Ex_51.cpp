#include <array>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

class Date {
public:
    Date(const std::string newDate) {
        auto date = newDate;
        std::string sMonth;

        for (auto &word : date) {
                word = tolower(word);
        }

        std::istringstream sDate(date);

        if (date.find_first_of("/._") != std::string::npos) {
            sDate >> month; 
            sDate.ignore();
            sDate >> day; 
            sDate.ignore();
            sDate >> year;
        } else {            
            sDate >> sMonth >> day; sDate.ignore(); sDate >> year;

            if (sMonth.find("jan") != std::string::npos) month = 1;
            else if (sMonth.find("fev") != std::string::npos) month = 2;
            else if (sMonth.find("mar") != std::string::npos) month = 3;
            else if (sMonth.find("apr") != std::string::npos) month = 4;
            else if (sMonth.find("may") != std::string::npos) month = 5;
            else if (sMonth.find("jun") != std::string::npos) month = 6;
            else if (sMonth.find("jul") != std::string::npos) month = 7;
            else if (sMonth.find("aug") != std::string::npos) month = 8;
            else if (sMonth.find("sep") != std::string::npos) month = 9;
            else if (sMonth.find("oct") != std::string::npos) month = 10;
            else if (sMonth.find("nov") != std::string::npos) month = 11;
            else if (sMonth.find("dec") != std::string::npos) month = 12;
        }
    }
    void print() {
        std::cout << "year: " << year 
                    << " month: " << month
                    << " day: " << day << std::endl;
    }

private:
    unsigned int year;
    unsigned int month;
    unsigned int day;

};

int main()
{
    Date date("January 5, 2023");
    date.print();

    Date date2("Fev 25, 2500");
    date2.print();
    
    Date date3("8/29/1984");
    date3.print();

    Date date4("12.26.1987");
    date4.print();

    Date date5("Fev 25 2030");
    date5.print();

    return 0;
}