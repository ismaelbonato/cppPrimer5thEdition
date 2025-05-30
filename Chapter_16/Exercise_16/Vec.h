#ifndef VEC_H
#define VEC_H

#include <iostream>
#include <memory>
#include <utility>

template<typename T>
class Vec;

template<typename T>
bool operator==(const Vec<T> &lhs, const Vec<T> &rhs);
template<typename T>
bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs);
template<typename T>
bool operator>(const Vec<T> &lhs, const Vec<T> &rhs);
template<typename T>
bool operator<(const Vec<T> &lhs, const Vec<T> &rhs);
template<typename T>
bool operator>=(const Vec<T> &lhs, const Vec<T> &rhs);
template<typename T>
bool operator<=(const Vec<T> &lhs, const Vec<T> &rhs);

template<typename T>
class Vec
{
    friend bool operator== <T>(const Vec<T> &lhs, const Vec<T> &rhs);
    friend bool operator!= <T>(const Vec<T> &lhs, const Vec<T> &rhs);
    friend bool operator> <T>(const Vec<T> &lhs, const Vec<T> &rhs);
    friend bool operator< <T>(const Vec<T> &lhs, const Vec<T> &rhs);
    friend bool operator>= <T>(const Vec<T> &lhs, const Vec<T> &rhs);
    friend bool operator<= <T>(const Vec<T> &lhs, const Vec<T> &rhs);

public:
    Vec()
        : elements(nullptr)
        , firstFree(nullptr)
        , cap(nullptr)
    {}
    Vec(const std::initializer_list<T> &);

    Vec(const Vec<T> &);
    ~Vec() { free(); }

    Vec &operator=(const Vec<T> &);
    T &operator[](const std::size_t idx);
    const T &operator[](const std::size_t idx) const;

    void push_back(const T &);
    T at(const std::size_t l) const { return *(elements + l); };

    T *begin() const { return elements; };
    T *end() const { return firstFree; };

    std::size_t size() const { return firstFree - elements; };
    std::size_t capacity() const { return cap - elements; };

private:
    void checkAndAlloc();
    std::pair<T *, T *> allocAndCopy(T *, T *);

    void free();
    void reallocate();

    std::allocator<T> alloc;

    T *elements;
    T *firstFree;
    T *cap;
};

template<typename T>
Vec<T>::Vec(const Vec<T> &origin)
{
    auto data = alloc.allocate(origin.size());
    elements = data;
    firstFree = std::uninitialized_copy(origin.elements, origin.firstFree, data);
    cap = firstFree;
}

template<typename T>
Vec<T> &Vec<T>::operator=(const Vec<T> &rhs)
{
    if (this == &rhs) {
        return *this;
    }

    auto data = allocAndCopy(rhs.elements, rhs.firstFree);
    free();
    elements = data.first;
    firstFree = cap = data.second;

    return *this;
}

template<typename T>
void Vec<T>::push_back(const T &s)
{
    checkAndAlloc();
    alloc.construct(firstFree, s);
    ++firstFree;
}

template<typename T>
void Vec<T>::checkAndAlloc()
{
    if (size() == capacity()) {
        reallocate();
    }
}

template<typename T>
void Vec<T>::free()
{
    if (elements == nullptr) {
        return;
    }

    auto p = firstFree;
    while (p != elements) {
        alloc.destroy(--p);
    }

    alloc.deallocate(elements, capacity());
}

template<typename T>
void Vec<T>::reallocate()
{
    auto newCap = size() * 2;

    if (newCap == 0)
        newCap = 1;

    auto data = alloc.allocate(newCap);

    auto pDestination = data;
    auto pElements = elements;

    for (size_t i = 0; i < size(); i++) {
        alloc.construct(pDestination++, std::move(*pElements));
        ++pElements;
    }

    free();
    elements = data;
    firstFree = pDestination;
    cap = elements + newCap;
}

template<typename T>
std::pair<T *, T *> Vec<T>::allocAndCopy(T *begin, T *end)
{
    auto data = alloc.allocate(end - begin);
    return {data, std::uninitialized_copy(begin, end, data)};
}

template<typename T>
Vec<T>::Vec(const std::initializer_list<T> &list)
{
    auto data = alloc.allocate(list.size());
    elements = data;
    firstFree = std::uninitialized_copy(list.begin(), list.end(), data);
    cap = firstFree;
}

template<typename T>
bool operator==(const Vec<T> &lhs, const Vec<T> &rhs)
{
    if (lhs.size() != rhs.size()) {
        return false;
    }

    return std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template<typename T>
bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs)
{
    return !(lhs == rhs);
}

template<typename T>
bool operator<(const Vec<T> &lhs, const Vec<T> &rhs)
{
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template<typename T>
bool operator>(const Vec<T> &lhs, const Vec<T> &rhs)
{
    return std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
}

template<typename T>
bool operator>=(const Vec<T> &lhs, const Vec<T> &rhs)
{
    return !(lhs < rhs);
}

template<typename T>
bool operator<=(const Vec<T> &lhs, const Vec<T> &rhs)
{
    return !(lhs > rhs);
}

template<typename T>
T &Vec<T>::operator[](const std::size_t idx)
{
    return *(elements + idx);
}
template<typename T>
const T &Vec<T>::operator[](const std::size_t idx) const
{
    return *(elements + idx);
};

#endif