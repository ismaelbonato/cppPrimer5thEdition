#ifndef BlobPtr_H
#define BlobPtr_H

#include "Blob.h"
#include <cstddef>
#include <memory>
#include <vector>

template<class T>
class Blob;

template<class T>
class BlobPtr;

template<class T> bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
template<class T> bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
template<class T> bool operator>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
template<class T> bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
template<class T> bool operator>=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
template<class T> bool operator<=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
template<class T> BlobPtr<T> operator+(const BlobPtr<T> &lhs, const std::size_t idx);
template<class T> BlobPtr<T> operator-(const BlobPtr<T> &lhs, const std::size_t idx);

template<class T>
class BlobPtr
{
    friend bool operator== <T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
    friend bool operator!= <T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
    friend bool operator> <T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
    friend bool operator< <T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
    friend bool operator>= <T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
    friend bool operator<= <T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
    friend BlobPtr<T> operator+ <T>(const BlobPtr<T> &lhs, const std::size_t idx);
    friend BlobPtr<T> operator- <T>(const BlobPtr<T> &lhs, const std::size_t idx);

public:
    using spVec = std::shared_ptr<std::vector<T>>;

    BlobPtr()
        : curr(0){};
    BlobPtr(Blob<T> &b, std::size_t sz = 0)
        : wptr(b.data)
        , curr(sz){};
    T &deref() const;

    T &operator[](const std::size_t idx);
    BlobPtr<T> &operator++();
    BlobPtr<T> &operator--();
    BlobPtr<T> operator++(int);
    BlobPtr<T> operator--(int);
    T &operator*() const;
    T *operator->() const;

private:
    spVec check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};


template <typename T>
typename BlobPtr<T>::spVec BlobPtr<T>::check(std::size_t sz, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound");
    } else if (sz >= ret->size()) {
        throw std::out_of_range(msg);
    }

    return ret;
}

template <typename T>
T &BlobPtr<T>::deref() const
{
    auto p = check(curr, "De-reference object");
    return (*p)[curr];
}

template <typename T>
T &BlobPtr<T>::operator[](const std::size_t idx)
{
    auto p = check(idx, "De-reference object");
    return (*p)[idx];
}

template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
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

template <typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    auto l = lhs.check(lhs.curr, "De-reference object");
    auto r = rhs.check(rhs.curr, "De-reference object");
    return std::lexicographical_compare(l->begin(), l->end(), r->begin(), r->end());
}

template <typename T>
bool operator>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    auto l = lhs.check(lhs.curr, "De-reference object");
    auto r = rhs.check(rhs.curr, "De-reference object");
    return std::lexicographical_compare(r->begin(), r->end(), l->begin(), l->end());
}

template <typename T>
bool operator>=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return !(lhs < rhs);
}

template <typename T>
bool operator<=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return !(lhs > rhs);
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++()
{
    check(curr, "Increment out of bound");
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator--()
{
    --curr;
    check(curr, "Decrement out of bound");
    return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    auto oldOne = *this;
    ++(*this);
    return oldOne;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
    auto oldOne = *this;
    --(*this);
    return oldOne;
}

template <typename T>
BlobPtr<T> operator+(const BlobPtr<T> &lhs, const std::size_t idx)
{   
    auto beg(lhs);
    beg.curr += idx;

    return beg;
}

template <typename T>
BlobPtr<T> operator-(const BlobPtr<T> &lhs, const std::size_t idx)
{
    auto beg(lhs);
    beg.curr -= idx;

    return beg;
}

template <typename T>
T &BlobPtr<T>::operator*() const
{
    auto p = check(curr, "De-reference object");
    return (*p)[curr];
}

template <typename T>
T *BlobPtr<T>::operator->() const
{
    return &(*this).operator*();
}

#endif