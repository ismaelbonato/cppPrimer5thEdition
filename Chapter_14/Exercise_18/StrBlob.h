#ifndef STRBLOB_H
#define STRBLOB_H

#include <exception>
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;
    friend bool operator==(StrBlob &lhs, StrBlob &rhs);
    friend bool operator!=(StrBlob &lhs, StrBlob &rhs);
    friend bool operator>( StrBlob &lhs,  StrBlob &rhs);
    friend bool operator<( StrBlob &lhs,  StrBlob &rhs);
    friend bool operator>=( StrBlob &lhs,  StrBlob &rhs);
    friend bool operator<=( StrBlob &lhs,  StrBlob &rhs);

public:
    using Data = std::shared_ptr<std::vector<std::string>>;

    StrBlob();
    StrBlob(std::initializer_list<std::string> il);

    std::size_t size() const { return data->size(); };
    bool empty() const { return data->empty(); };

    void push_back(const std::string &t) const;
    void pop_back() const;
    // element access
    std::string &front();
    std::string &back();

    StrBlobPtr begin();
    StrBlobPtr end();

private:
    Data data;
    void check(std::size_t i, const std::string &msg) const;
};

#endif