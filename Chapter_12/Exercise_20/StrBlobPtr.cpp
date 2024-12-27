#include "StrBlobPtr.h"
#include <stdexcept>

StrBlobPtr::spVecOfStr StrBlobPtr::check(std::size_t sz, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound");
    } else if (sz >= ret->size()) {
        throw std::out_of_range(msg);
    }

    return ret;
}

std::string &StrBlobPtr::deref() const
{
    auto p = check(curr, "De-reference object");
    return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "Increment out of bound");
    ++curr;
    return *this;
}
