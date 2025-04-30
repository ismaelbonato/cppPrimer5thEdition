#include "StrVec.h"

StrVec::StrVec(const StrVec &origin) 
{
    auto data = alloc.allocate(origin.size());
    elements = data;
    firstFree = std::uninitialized_copy(origin.elements, origin.firstFree, data);
    cap = firstFree;
}

StrVec &StrVec::operator=(const StrVec &rhs)
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

void StrVec::push_back(const std::string &s)
{
    checkAndAlloc();
    alloc.construct(firstFree, s);
    ++firstFree;
}

void StrVec::checkAndAlloc()
{
    if (size() == capacity()) {
        reallocate();
    }
}

void StrVec::free()
{
    if (elements == nullptr) {
        return;
    }

    auto p = firstFree;
    while (p != elements)
    {
        alloc.destroy(--p);
    }

    alloc.deallocate(elements, capacity());
}

void StrVec::reallocate()
{
    auto newCap = size() * 2;

    if (newCap == 0) newCap = 1; 

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

std::pair<std::string *, std::string *> StrVec::allocAndCopy(std::string *begin,
                                                             std::string *end)
{
    auto data = alloc.allocate(end - begin);
    return {data, std::uninitialized_copy(begin, end, data)};
}

StrVec::StrVec(const std::initializer_list<std::string> &list) 
{
    auto data = alloc.allocate(list.size());
    elements = data;
    firstFree = std::uninitialized_copy(list.begin(), list.end(), data);
    cap = firstFree;
}
