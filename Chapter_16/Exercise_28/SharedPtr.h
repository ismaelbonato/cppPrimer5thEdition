#ifndef SHAREDPTR_H
#define SHAREDPTR_H

#include <cstddef>
#include <functional>
#include <iostream>

template<typename T>
class SharedPtr;

template<typename T>
bool operator==(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs);
template<typename T>
bool operator!=(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs);
template<typename T>
bool operator!(const SharedPtr<T> &lhs);

template<typename T>
class SharedPtr
{
    friend bool operator== <T>(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs);
    friend bool operator!= <T>(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs);
    friend bool operator! <T>(const SharedPtr<T> &lhs);

public:
    SharedPtr()
        : p(nullptr)
        , counter(nullptr)
        , del(nullptr)
    {
        //std::cout << "SharedPtr default constructor called" << std::endl;
    }

    SharedPtr(T *ptr, std::function<void(T *)> f = nullptr)
        : p(ptr)
        , counter(new std::size_t(1))
        , del(f)
    {
        //std::cout << "SharedPtr constructor with custom deleter called" << std::endl;
    }

    SharedPtr(const SharedPtr &origin)
        : p(origin.p)
        , counter(origin.counter)
        , del(origin.del)
    {
        ++(*counter);
        //std::cout << "SharedPtr copy constructor called" << std::endl;
    }

    SharedPtr(SharedPtr &&origin)
        : p(origin.p)
        , counter(origin.counter)
        , del(std::move(origin.del))
    {
        origin.p = nullptr;
        origin.counter = nullptr;

        //std::cout << "SharedPtr move constructor called" << std::endl;
    }

    SharedPtr &operator=(const SharedPtr &rhs)
    {
        if (this == &rhs)
            return *this;
        if (counter) {
            --(*counter);
            if (*counter == 0) {
                del ? del(p) : delete p;
                delete counter;
            }
        }

        p = rhs.p;
        counter = rhs.counter;
        del = rhs.del;

        return *this;
    }

    T &operator*() const { return *p; }

    T *operator->() const { return p; }

    SharedPtr &operator=(SharedPtr &&rhs)
    {
        if (this == &rhs)
            return *this;
        if (counter) {
            --(*counter);
            if (*counter == 0) {
                del ? del(p) : delete p;
                delete counter;
            }
        }

        p = rhs.p;
        counter = rhs.counter;
        del = std::move(rhs.del);

        rhs.p = nullptr;
        rhs.counter = nullptr;

        return *this;
    }

    ~SharedPtr()
    {
        if (!counter)
            return;

        --(*counter);
        if (*counter == 0) {
            del ? del(p) : delete p;
            delete counter;
        }
        //std::cout << "SharedPtr destructor called" << std::endl;
    }

    operator bool() const { return p != nullptr; };

private:
    T *p;
    std::size_t *counter;
    std::function<void(T *)> del;
};

template<typename T>
bool operator==(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs)
{
    return lhs.p == rhs.p;
}

template<typename T>
bool operator!=(const SharedPtr<T> &lhs, const SharedPtr<T> &rhs)
{
    return !(lhs.p == rhs.p);
}

template<typename T>
bool operator!(const SharedPtr<T> &lhs)
{
    return !lhs.p;
}

#endif