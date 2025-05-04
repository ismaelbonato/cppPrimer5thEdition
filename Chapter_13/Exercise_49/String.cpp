#include "String.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>

String::String(const std::initializer_list<const char> &list)
{
    auto data = allocAndCopy(list.begin(), list.end());
    elements = data.first;
    cap = firstFree = data.second;
}

String::String(const String &origin)
{
    std::cout << "Copy constructor called" << std::endl;
    auto data = allocAndCopy(origin.begin(), origin.end());

    elements = data.first;
    cap = firstFree = data.second;
}

String &String::operator=(const String &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &rhs) {
        return *this;
    }

    auto data = allocAndCopy(rhs.begin(), rhs.end());

    free();
    elements = data.first;
    firstFree = cap = data.second;

    return *this;
}

String::~String()
{
    free();
}

void String::push_back(const char &c)
{
    checkAndAlloc();
    alloc.construct(firstFree, c);
    ++firstFree;
}

void String::checkAndAlloc()
{
    if (size() == capacity()) {
        reallocate();
    }
}

std::pair<char *, char *> String::allocAndCopy(const char *a, const char *b)
{
    auto data = alloc.allocate(b - a);
    return {data, std::uninitialized_copy(a, b, data)};
}

void String::free()
{
    if (elements == nullptr) {
        return;
    }

    std::for_each(rbegin(), rend(), [this](char &c) { alloc.destroy(&c); });

    alloc.deallocate(elements, capacity());
}

void String::reallocate()
{
    auto newCapacity = capacity() * 2;
    if (newCapacity == 0)
        newCapacity = 1;

    auto data = alloc.allocate(newCapacity);

    auto pElements = elements;
    auto pDestination = data;

    try {
        for (size_t i = 0; i < size(); i++) {
            alloc.construct(pDestination++, std::move(*pElements));
            ++pElements;
        }
    } catch (const std::exception &e) {
        while (pDestination != data) {
            alloc.destroy(pDestination);
            --pDestination;
        }
        alloc.deallocate(data, newCapacity);
        throw;
    }

    free();
    elements = data;
    firstFree = pDestination;
    cap = data + newCapacity;
}

String::String(String &&origin) noexcept
    : elements(origin.elements)
    , firstFree(origin.firstFree)
    , cap(origin.cap)
{
    origin.elements = nullptr;
    origin.firstFree = nullptr;
    origin.cap = nullptr;
}

String &String::operator=(String &&rhs)
{
    if (this == &rhs) {
        return *this;
    }

    free();
    auto data = alloc.allocate(rhs.size());
    elements = data;
    firstFree = std::uninitialized_copy(std::make_move_iterator(rhs.begin()),
                                        std::make_move_iterator(rhs.end()),
                                        data);

    cap = firstFree;

    rhs.elements = rhs.firstFree = rhs.cap = nullptr;

    return *this;
}
