#include <iostream>
#include <string>
#include <vector>

class Employee
{
private:

public:
    Employee(/* args */) : name(""), id(++idCounter) {
        std::cout << "Employee created: " << name << ", ID: " << id << std::endl;
    };
    Employee(std::string name) : name(name), id(++idCounter) {
        std::cout << "Employee created: " << name << ", ID: " << id << std::endl;
    }

    std::string name;
    int id;
    static int idCounter;
};

// Initialize the static member outside the class
int Employee::idCounter = 0;

int main()
{
    Employee emp1("John Doe");
    Employee emp2("Jane Smith");
    Employee emp3("Alice Johnson");
    Employee emp4("Bob Brown");
    Employee emp5("Charlie Black");
    Employee emp6("Diana White");

    Employee emp7 = emp1; // Copy constructor
    
    std::cout << "Employee emp7 = emp1; " << emp7.name << ", ID: " << emp7.id << std::endl;

    Employee emp8(emp1); // Copy constructor

    std::cout << "Employee emp8(emp1);" << emp8.name << ", ID: " << emp8.id << std::endl;

    Employee emp9; // Default constructor

    std::cout << "Employee emp9;" << emp9.name << ", ID: " << emp9.id << std::endl;

    emp9 = emp2; // Copy constructor
    
    std::cout << "emp9 = emp2;" << emp9.name << ", ID: " << emp9.id << std::endl;

    return 0;
}