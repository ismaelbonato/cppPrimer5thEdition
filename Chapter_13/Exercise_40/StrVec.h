#ifndef STRVEC_H
#define STRVEC_H

#include <iostream>
#include <memory>
#include <utility>

class StrVec
{
public:
    StrVec()
        : elements(nullptr)
        , firstFree(nullptr)
        , cap(nullptr)
    {}
    StrVec(const std::initializer_list<const std::string> &);

    StrVec(const StrVec &);
    ~StrVec() { free(); }

    StrVec &operator=(const StrVec &);

    void push_back(const std::string &);

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