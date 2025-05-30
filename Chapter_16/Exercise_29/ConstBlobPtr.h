#ifndef CONSTBLOBPTR_H
#define CONSTBLOBPTR_H

#include "Blob.h"
#include <cstddef>
#include <memory>
#include <vector>

template<class T>
class Blob;

template<class T>
class ConstBlobPtr;

template<typename T>
ConstBlobPtr<T> operator+(const ConstBlobPtr<T> &lhs, const std::size_t idx);
template<typename T>
ConstBlobPtr<T> operator-(const ConstBlobPtr<T> &lhs, const std::size_t idx);

template<class T>
class ConstBlobPtr
{
    friend ConstBlobPtr<T> operator+ <T>(const ConstBlobPtr<T> &lhs,
                                         const std::size_t idx);
    friend ConstBlobPtr<T> operator- <T>(const ConstBlobPtr<T> &lhs,
                                         const std::size_t idx);

public:
    using spVec = std::shared_ptr<std::vector<T>>;

    ConstBlobPtr()
        : curr(0){};
    ConstBlobPtr(const Blob<T> &b, std::size_t sz = 0)
        : wptr(b.data)
        , curr(sz){};
    T &deref() const;
    ConstBlobPtr<T> &incr();

    const T &operator[](const std::size_t idx) const;
    T &operator*() const;
    T *operator->() const;

private:
    spVec check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<T>> const wptr;
    std::size_t curr;
};

template<typename T>
typename ConstBlobPtr<T>::spVec ConstBlobPtr<T>::check(std::size_t sz,
                                                   const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound");
    } else if (sz >= ret->size()) {
        throw std::out_of_range(msg);
    }

    return ret;
}

template<typename T>
T &ConstBlobPtr<T>::deref() const
{
    auto p = check(curr, "De-reference object");
    return (*p)[curr];
}

template<typename T>
ConstBlobPtr<T> &ConstBlobPtr<T>::incr()
{
    check(curr, "Increment out of bound");
    ++curr;
    return *this;
}

template<typename T>
const T &ConstBlobPtr<T>::operator[](const std::size_t idx) const
{
    auto p = check(idx, "De-reference object");
    return (*p)[idx];
}

template<typename T>
ConstBlobPtr<T> operator+(const ConstBlobPtr<T> &lhs, const std::size_t idx)
{
    auto beg(lhs);
    beg.curr += idx;

    return beg;
}

template<typename T>
ConstBlobPtr<T> operator-(const ConstBlobPtr<T> &lhs, const std::size_t idx)
{
    auto beg(lhs);
    beg.curr -= idx;

    return beg;
}

template<typename T>
T &ConstBlobPtr<T>::operator*() const
{
    auto p = check(curr, "De-reference object");
    return (*p)[curr];
}

template<typename T>
T *ConstBlobPtr<T>::operator->() const
{
    return &(*this).operator*();
}

#endif