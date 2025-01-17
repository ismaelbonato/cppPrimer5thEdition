#include "StrBlob.h"
#include <cstddef>
#include "StrBlobPtr.h"
#include "ConstStrBlobPtr.h"

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
void StrBlob::pop_back() const
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

std::string &StrBlob::at(std::size_t idx) const
{
    check(idx, "front on empty StrBlob");
    return data->at(idx);
 
}


void StrBlob::push_back(const std::string &t) const
{
    data->push_back(t);
}

void StrBlob::check(std::size_t i, const std::string &msg) const
{
    if (i >= data->size()) throw std::out_of_range(msg);
}

StrBlobPtr StrBlob::begin()
{ 
    return StrBlobPtr(*this); 
}

StrBlobPtr StrBlob::end()
{ 
    return StrBlobPtr(*this, data->size()); 
}

ConstStrBlobPtr StrBlob::cbegin() const
{ 
    return ConstStrBlobPtr( *this );
}

ConstStrBlobPtr StrBlob::cend() const
{ 
    return ConstStrBlobPtr(*this, data->size());
}
