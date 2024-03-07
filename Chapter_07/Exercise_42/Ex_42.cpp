#include <istream>
#include <sstream>
#include <string>
#include <iostream>


class Vehicle {
public:
    Vehicle(const std::string iModel = ""): 
        Vehicle(iModel, "", "", 0) {};

    Vehicle(const std::string &iModel, 
            const std::string &iType, 
            const std::string &iBrand, 
            const unsigned int iYear):
        model(iModel), type(iType), brand(iBrand), year(iYear) {};

    Vehicle(std::istream &is) {
        is >> model >> type >> brand >> year;
    };

    std::ostream &print(std::ostream &os = std::cout) const {
        os << model << " " << type << " " << brand << " " << year;
        return os;
    };

private:
    std::string model;
    std::string type;
    std::string brand;
    unsigned int year = 0;
};

int main()
{

    Vehicle c300;

    c300.print() << std::endl;

//-------------------------------
    Vehicle ford("mustang");

    ford.print() << std::endl;

//------------------------------
    Vehicle camaro("camaro", "car", "chevrolet", 2024);
    camaro.print() << std::endl;

//------------------------------
    std::stringstream ios;
    std::string car = "mustang car ford 2024";

    ios << car;
    Vehicle mustang(ios);

    mustang.print() << std::endl;

    return 0;
}
