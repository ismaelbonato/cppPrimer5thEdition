#ifndef STRVEC_H
#define STRVEC_H

#include <iostream>
#include <memory>
#include <utility>

class StrVec
{
    friend bool operator==(const StrVec &lhs, const StrVec &rhs);
    friend bool operator!=(const StrVec &lhs, const StrVec &rhs);
    friend bool operator>(const StrVec &lhs, const StrVec &rhs);
    friend bool operator<(const StrVec &lhs, const StrVec &rhs);
    friend bool operator>=(const StrVec &lhs, const StrVec &rhs);
    friend bool operator<=(const StrVec &lhs, const StrVec &rhs);

public:
    StrVec()
        : elements(nullptr)
        , firstFree(nullptr)
        , cap(nullptr)
    {}
    StrVec(const std::initializer_list<std::string> &);

    StrVec(const StrVec &);
    ~StrVec() { free(); }

    StrVec &operator=(const StrVec &);
    StrVec &operator=(const std::initializer_list<std::string> &l);

    void push_back(const std::string &);
    std::string at(const std::size_t l) const {return *(elements+l);};

    std::string *begin() const { return elements; };
    std::string *end() const { return firstFree; };

    std::size_t size() const {return firstFree - elements;};
    std::size_t capacity() const {return cap - elements;};

private:
    void checkAndAlloc();
    std::pair<std::string *, std::string *> allocAndCopy(std::string *, std::string *);

    void free();
    void reallocate();

    std::allocator<std::string> alloc;

    std::string *elements;
    std::string *firstFree;
    std::string *cap;
};

#endif