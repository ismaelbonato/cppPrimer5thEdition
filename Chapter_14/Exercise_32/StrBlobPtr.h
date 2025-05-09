#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include "StrBlob.h"
#include <cstddef>
#include <memory>
#include <vector>

class StrBlobPtr
{
    friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend StrBlobPtr operator+(const StrBlobPtr &lhs, const std::size_t idx);
    friend StrBlobPtr operator-(const StrBlobPtr &lhs, const std::size_t idx);

public:
    using spVecOfStr = std::shared_ptr<std::vector<std::string>>;

    StrBlobPtr()
        : curr(0){};
    StrBlobPtr(StrBlob &b, std::size_t sz = 0)
        : wptr(b.data)
        , curr(sz){};
    std::string &deref() const;

    std::string &operator[](const std::size_t idx);
    StrBlobPtr &operator++();
    StrBlobPtr &operator--();
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);
    std::string &operator*() const;
    std::string *operator->() const;

private: 

    spVecOfStr check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

#endif