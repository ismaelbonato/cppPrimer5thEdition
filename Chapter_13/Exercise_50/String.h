#ifndef STRING_H
#define STRING_H

#include <iterator>
#include <utility>

class String
{
public:
    String()
        : elements(nullptr)
        , firstFree(nullptr)
        , cap(nullptr){};

    String(const std::initializer_list<const char> &list);

    String(const String &);

    String(String &&) noexcept;
    

    String &operator=(const String &);
    String &operator=(String &&);

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

#endif