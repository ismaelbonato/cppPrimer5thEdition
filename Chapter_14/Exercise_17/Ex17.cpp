#include <iostream>
#include <istream>
#include <sstream>
#include <string>

class Vehicle
{
    friend std::ostream &operator<<(std::ostream &, const Vehicle &);
    friend std::istream &operator>>(std::istream &, Vehicle &);
    friend bool operator==(const Vehicle &, const Vehicle &);
    friend bool operator!=(const Vehicle &, const Vehicle &);

public:
    Vehicle(const std::string iModel = "")
        : Vehicle(iModel, "", "", 0){};

    Vehicle(const std::string &iModel,
            const std::string &iType,
            const std::string &iBrand,
            const unsigned int iYear)
        : model(iModel)
        , type(iType)
        , brand(iBrand)
        , year(iYear){};

    Vehicle(std::istream &is) { is >> *this; };

private:
    std::string model;
    std::string type;
    std::string brand;
    unsigned int year = 0;
};

bool operator==(const Vehicle &lhs, const Vehicle &rhs)
{
    return (lhs.model == rhs.model) && 
           (lhs.type == rhs.type) && 
           (lhs.brand == rhs.brand) && 
           (lhs.year == rhs.year);
}

bool operator!=(const Vehicle &lhs, const Vehicle &rhs)
{
    return !(lhs == rhs);
}

std::ostream &operator<<(std::ostream &os, const Vehicle &v)
{
    os << v.model << " " << v.type << " " << v.brand << " " << v.year;
    return os;
};

std::istream &operator>>(std::istream &is, Vehicle &v)
{
    is >> v.model >> v.type >> v.brand >> v.year;
    if (is) {
        v = Vehicle();
    }

    return is;
};

int main()
{
    Vehicle c300;

    std::cout << c300 << std::endl;

    //-------------------------------
    Vehicle ford("mustang");

    std::cout << ford << std::endl;

    //------------------------------
    Vehicle camaro("camaro", "car", "chevrolet", 2024);
    std::cout << camaro << std::endl;

    //------------------------------
    std::stringstream ios;
    std::string car = "mustang car ford 2024";

    ios << car;
    Vehicle mustang(ios);

    std::cout << mustang << std::endl;

    return 0;
}
