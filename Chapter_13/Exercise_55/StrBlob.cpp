#include "StrBlob.h"

StrBlob::StrBlob(): data(std::make_shared<std::vector<std::string>>()) 
{
}


StrBlob::StrBlob(std::initializer_list<std::string> il): 
                data(std::make_shared<std::vector<std::string>>(il))
{
}

std::string& StrBlob::front()
{
// if the vector is empty, check will throw
    check(0, "front on empty StrBlob");
    return data->front();
}
std::string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}
void StrBlob::pop_back() const &
{
    check(0, "pop_back on empty StrBlob");
    std::cout << "StrBlob::pop_back() const & called" << std::endl;
    data->pop_back();
}

void StrBlob::pop_back() &&
{
    check(0, "pop_back on empty StrBlob");
    std::cout << "StrBlob::pop_back() && called" << std::endl;
    data->pop_back();
}

void StrBlob::push_back(const std::string &t) const &
{

    data->push_back(t);
    std::cout << "StrBlob::push_back(const std::string &t) const & called" << std::endl;
}

void StrBlob::push_back(const std::string &t)  &&
{
    data->push_back(t);
    std::cout << "StrBlob::push_back(const std::string &t) && called" << std::endl;
}

void StrBlob::check(size_type i, const std::string &msg) const
{
    if (i >= data->size()) throw std::out_of_range(msg);
}
