#ifndef CONSTSTRBLOBPTR_H
#define CONSTSTRBLOBPTR_H

#include <cstddef>
#include <memory>
#include <vector>
#include "StrBlob.h"

class ConstStrBlobPtr {
public:
    using spVecOfStr = std::shared_ptr<std::vector<std::string>>;

    ConstStrBlobPtr(): curr(0) {};
    ConstStrBlobPtr(const StrBlob &b, std::size_t sz = 0): wptr(b.data), curr(sz) {};   
    std::string &deref() const;
    ConstStrBlobPtr &incr();

    const std::string &operator[](const std::size_t idx) const;

private:
    spVecOfStr check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<std::string>> const wptr;
    std::size_t curr;
};

#endif