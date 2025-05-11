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

    Vehicle(std::istream &is) { is >> (*this); }
    explicit operator bool() const 
    {
        return (!model.empty() && !type.empty() && !brand.empty() && year); 
    }

private:
    std::string model;
    std::string type;
    std::string brand;
    unsigned int year;
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
    if (!is) {
        v = Vehicle();
    }

    return is;
};

int main()
{
    Vehicle c300;

    if (static_cast<bool>(c300)) {
        std::cout << c300 << std::endl;
    }
    //-------------------------------
    Vehicle ford("mustang");

    if (ford) {
        std::cout << ford << std::endl;
    }
    //------------------------------
    Vehicle camaro("camaro", "car", "chevrolet", 2024);
    
    if (camaro) {
        std::cout << camaro << std::endl;
    }
    //------------------------------
    
    std::stringstream ios{"mustang car ford 2024"};
    
    Vehicle mustang{ios};

    if (mustang) {
        std::cout << mustang << std::endl;
    }

    return 0;
}
