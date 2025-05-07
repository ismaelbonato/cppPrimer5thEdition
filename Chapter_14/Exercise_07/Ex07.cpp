#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <memory>
#include <utility>

class String
{
    friend std::ostream &operator<<(std::ostream &os, const String &);

public:
    String()
        : elements(nullptr)
        , firstFree(nullptr)
        , cap(nullptr){};

    String(const std::initializer_list<const char> &list);

    String(const String &);

    String &operator=(const String &);

    ~String();

    char *begin() const { return elements; };
    char *end() const { return firstFree; };

    std::reverse_iterator<char *> rbegin()
    {
        return std::reverse_iterator<char *>(firstFree);
    };
    std::reverse_iterator<char *> rend()
    {
        return std::reverse_iterator<char *>(elements);
    };

    std::size_t size() const { return firstFree - elements; };
    std::size_t capacity() const { return cap - elements; };

    void push_back(const char &);

private:
    void checkAndAlloc();
    std::pair<char *, char *> allocAndCopy(const char *a, const char *b);

    void free();
    void reallocate();

    std::allocator<char> alloc;
    char *elements;
    char *firstFree;
    char *cap;
};

std::ostream &operator<<(std::ostream &os, const String &s)
{
    for (auto c : s) {
        os << c;
    }

    return os;
}

String::String(const std::initializer_list<const char> &list)
{
    auto data = allocAndCopy(list.begin(), list.end());
    elements = data.first;
    cap = firstFree = data.second;
}

String::String(const String &origin)
{
    auto data = allocAndCopy(origin.begin(), origin.end());

    elements = data.first;
    cap = firstFree = data.second;
}

String &String::operator=(const String &rhs)
{
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

int main()
{
    String str1{'H', 'e', 'l', 'l', 'o', '!'};
    String str2{str1};
    String str3;

    std::cout << str1 << std::endl;

    std::cout << str2 << std::endl;

    str3 = str2;

    std::cout << str3 << std::endl;

    return 0;
}