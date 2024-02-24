#ifndef PERSON_H
#define PERSON_H

#include <istream>
#include <ostream>
#include <string>

struct Person;
std::istream &read(std::istream &in, Person &person);

struct Person {

friend std::istream &read(std::istream &in, Person &person);

private:
    std::string name;
    std::string address;

public:
    Person(std::istream &in) { read(in, *this); };
    Person(const std::string &name, const std::string &address): 
        name(name), address(address) {};

    const std::string &getName() const { return name; };
    const std::string &getAddress() const { return address; };

};

std::istream &read(std::istream &in, Person &person)
{
    in >> person.name;
    std::getline(in, person.address);
    return in;
}
std::ostream &print(std::ostream &out, const Person &person)
{
    out << "Name: " << person.getName() << " Address:" << person.getAddress();

    return out;
}

#endif //PERSON_H