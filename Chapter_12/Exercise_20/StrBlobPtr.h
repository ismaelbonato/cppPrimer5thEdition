#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include <cstddef>
#include <memory>
#include <vector>
#include "StrBlob.h"

class StrBlobPtr {
public:
    using spVecOfStr = std::shared_ptr<std::vector<std::string>>;

    StrBlobPtr(): curr(0) {};
    StrBlobPtr(StrBlob &b, std::size_t sz = 0): wptr(b.data), curr(sz) {};   
    std::string &deref() const;
    StrBlobPtr &incr();
private:
    spVecOfStr check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

#endif