#include "StrBlobPtr.h"
#include <stdexcept>
#include <string>

StrBlobPtr::spVecOfStr StrBlobPtr::check(std::size_t sz, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound");
    } else if (sz >= ret->size()) {
        throw std::out_of_range(msg);
    }

    return ret;
}

std::string &StrBlobPtr::deref() const
{
    auto p = check(curr, "De-reference object");
    return (*p)[curr];
}

std::string &StrBlobPtr::operator[](const std::size_t idx)
{
    auto p = check(idx, "De-reference object");
    return (*p)[idx];
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    if (lhs.curr != rhs.curr) {
        return false;
    }

    auto l = lhs.wptr.lock();
    if (!l) {
        throw std::runtime_error("lhs unbound");
    }

    auto r = rhs.wptr.lock();
    if (!r) {
        throw std::runtime_error("rhs unbound");
    }

    return std::equal(l->begin(), l->end(), r->begin());
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.check(lhs.curr, "De-reference object");
    auto r = rhs.check(rhs.curr, "De-reference object");
    return std::lexicographical_compare(l->begin(), l->end(), r->begin(), r->end());
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.check(lhs.curr, "De-reference object");
    auto r = rhs.check(rhs.curr, "De-reference object");
    return std::lexicographical_compare(r->begin(), r->end(), l->begin(), l->end());}

bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs < rhs);
}

bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs > rhs);
}

StrBlobPtr &StrBlobPtr::operator++()
{
    check(curr, "Increment out of bound");
    ++curr;
    return *this;
}

StrBlobPtr &StrBlobPtr::operator--()
{
    --curr;
    check(curr, "Decrement out of bound");
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
    auto oldOne = *this;
    ++(*this);
    return oldOne;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
    auto oldOne = *this;
    --(*this);
    return oldOne;
}

StrBlobPtr operator+(const StrBlobPtr &lhs, const std::size_t idx)
{   
    auto beg(lhs);
    beg.curr += idx;

    return beg;
}

StrBlobPtr operator-(const StrBlobPtr &lhs, const std::size_t idx)
{
    auto beg(lhs);
    beg.curr -= idx;

    return beg;
}

std::string &StrBlobPtr::operator*() const
{
    auto p = check(curr, "De-reference object");
    return (*p)[curr];
}

std::string *StrBlobPtr::operator->() const
{
    return &(*this).operator*();
}