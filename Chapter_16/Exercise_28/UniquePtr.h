#ifndef UNIQUEPTR_H
#define UNIQUEPTR_H

#include <functional>

template<typename T>
struct defaultDeleter
{
    void operator()(T *ptr) const { delete ptr; }
};

template<typename T, typename D = defaultDeleter<T>>
class UniquePtr
{
public:
    UniquePtr()
        : p(nullptr)
        , del(D())
    {}

    UniquePtr(T *ptr, D deleter = D())
        : p(ptr)
        , del(deleter)
    {}

    UniquePtr(const UniquePtr &origin) = delete;

    UniquePtr(UniquePtr &&origin)
        : p(origin.p)
        , del(std::move(origin.del))
    {
        origin.p = nullptr;
    }

    UniquePtr &operator=(const UniquePtr &rhs) = delete;

    UniquePtr &operator=(UniquePtr &&rhs)
    {
        if (this == &rhs) {
            return *this;
        }
        if (p) {
            delete p;
        }
        p = rhs.p;
        del = std::move(rhs.del);
    }

    T &operator*() const { return *p; }
    T *operator->() const { return p; }

    ~UniquePtr() { del(p); }

private:
    T *p;
    D del;
};

#endif