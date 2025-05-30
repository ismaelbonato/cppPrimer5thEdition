#ifndef BLOB_H
#define BLOB_H

#include "BlobPtr.h"
#include "ConstBlobPtr.h"
#include <exception>
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

template<class T>
class BlobPtr;
template<class T>
class ConstBlobPtr;

template<typename>
class Blob;

template<typename T>
bool operator==(const Blob<T> &, const Blob<T> &);
template<typename T>
bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs);
template<typename T>
bool operator>(const Blob<T> &lhs, const Blob<T> &rhs);
template<typename T>
bool operator<(const Blob<T> &lhs, const Blob<T> &rhs);
template<typename T>
bool operator>=(const Blob<T> &lhs, const Blob<T> &rhs);
template<typename T>
bool operator<=(const Blob<T> &lhs, const Blob<T> &rhs);

template<class T>
class Blob
{
    friend class BlobPtr<T>;
    friend class ConstBlobPtr<T>;
    friend bool operator== <T>(const Blob<T> &lhs, const Blob<T> &rhs);
    friend bool operator!= <T>(const Blob<T> &lhs, const Blob<T> &rhs);
    friend bool operator><T>(const Blob<T> &lhs, const Blob<T> &rhs);
    friend bool operator< <T>(const Blob<T> &lhs, const Blob<T> &rhs);
    friend bool operator>= <T>(const Blob<T> &lhs, const Blob<T> &rhs);
    friend bool operator<= <T>(const Blob<T> &lhs, const Blob<T> &rhs);

public:
    using Data = std::shared_ptr<std::vector<T>>;

    Blob();
    Blob(std::initializer_list<T> il);
    template<typename IT>
    Blob(const IT &begin, const IT &end);

    std::size_t size() const { return data->size(); };
    bool empty() const { return data->empty(); };

    void push_back(const T &t) const;
    void pop_back() const;
    // element access
    T &front();
    T &back();

    BlobPtr<T> begin();
    BlobPtr<T> end();

    ConstBlobPtr<T> cbegin() const;
    ConstBlobPtr<T> cend() const;

    T &operator[](const std::size_t idx);
    const T &operator[](const std::size_t idx) const;

private:
    Data data;
    void check(std::size_t i, const std::string &msg) const;
};

template<typename T>
Blob<T>::Blob()
    : data(std::make_shared<std::vector<T>>())
{}

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il)
    : data(std::make_shared<std::vector<T>>(il))
{}

template<typename T>
template<typename IT>
Blob<T>::Blob(const IT &begin, const IT &end)
    : data(std::make_shared<std::vector<T>>(begin, end))
{}

template<typename T>
T &Blob<T>::front()
{
    // if the vector is empty, check will throw
    check(0, "front on empty Blob");
    return data->front();
}

template<typename T>
T &Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}

template<typename T>
void Blob<T>::pop_back() const
{
    check(0, "pop_back on empty Blob");
    data->pop_back();
}
template<typename T>
void Blob<T>::push_back(const T &t) const
{
    data->push_back(t);
}

template<typename T>
void Blob<T>::check(std::size_t i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template<typename T>
BlobPtr<T> Blob<T>::begin()
{
    return BlobPtr<T>(*this);
}

template<typename T>
BlobPtr<T> Blob<T>::end()
{
    return BlobPtr<T>(*this, data->size());
}

template<typename T>
ConstBlobPtr<T> Blob<T>::cbegin() const
{
    return ConstBlobPtr<T>(*this);
}

template<typename T>
ConstBlobPtr<T> Blob<T>::cend() const
{
    return ConstBlobPtr<T>(*this, data->size());
}

template<typename T>
bool operator==(Blob<T> &lhs, Blob<T> &rhs)
{
    return *(lhs.data) == *(rhs.data);
}

template<typename T>
bool operator!=(Blob<T> &lhs, Blob<T> &rhs)
{
    return !(lhs == rhs);
}

template<typename T>
bool operator<(Blob<T> &lhs, Blob<T> &rhs)
{
    return (*(lhs.data) < *(rhs.data));
}

template<typename T>
bool operator>(Blob<T> &lhs, Blob<T> &rhs)
{
    return (*(lhs.data) > *(rhs.data));
}

template<typename T>
bool operator>=(Blob<T> &lhs, Blob<T> &rhs)
{
    return !(*(lhs.data) < *(rhs.data));
}

template<typename T>
bool operator<=(Blob<T> &lhs, Blob<T> &rhs)
{
    return !(lhs > rhs);
}

template<typename T>
T &Blob<T>::operator[](const std::size_t idx)
{
    return data->at(idx);
}

template<typename T>
const T &Blob<T>::operator[](const std::size_t idx) const
{
    return data->at(idx);
}

#endif
