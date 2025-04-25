#ifndef STRBLOB_H
#define STRBLOB_H

#include <initializer_list>
#include <memory>
#include <vector>
#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>

class StrBlob {
public:
    using size_type = std::vector<std::string>::size_type;
    using Data = std::shared_ptr<std::vector<std::string>>;

    StrBlob();
    StrBlob(std::initializer_list<std::string> il);

    StrBlob(const StrBlob &origin) : 
            data(std::make_shared<std::vector<std::string>>(*origin.data)) { 

        std::cout << "StrBlob(const StrBlob &origin) called" << std::endl;
            }

    StrBlob& operator=(const StrBlob &origin) {
        auto tmpData = std::make_shared<std::vector<std::string>>(*origin.data);
        data = tmpData;

        std::cout << "StrBlob& operator=() called" << std::endl;
        return *this;
    }

    
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const std::string &t) const;
    void pop_back() const;
    // element access
    std::string& front();
    std::string& back();

private:
    Data data;

    void check(size_type i, const std::string &msg) const;
};

#endif