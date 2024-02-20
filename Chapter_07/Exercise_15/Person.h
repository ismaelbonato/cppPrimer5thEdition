#ifndef PERSON_H
#define PERSON_H

#include <istream>
#include <ostream>
#include <string>

struct Person;
std::istream &read(std::istream &in, Person &person);

struct Person {
    std::string name;
    std::string address;

    Person(std::istream &in) { read(in, *this); };

    const std::string getName() const { return name; };
    const std::string getAddress() const { return address; };
};

std::istream &read(std::istream &in, Person &person)
{
    in >> person.name;
    std::getline(in, person.address);
    return in;
}
std::ostream &print(std::ostream &out, const Person &person)
{
    out << "Name: " << person.getName()
    << " Address:" << person.getAddress() << std::endl;

    return out;
}

#endif //PERSON_H