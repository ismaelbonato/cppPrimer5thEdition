#include "ConstStrBlobPtr.h"
#include <stdexcept>

ConstStrBlobPtr::spVecOfStr ConstStrBlobPtr::check(std::size_t sz, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound");
    } else if (sz >= ret->size()) {
        throw std::out_of_range(msg);
    }

    return ret;
}

std::string &ConstStrBlobPtr::deref() const
{
    auto p = check(curr, "De-reference object");
    return (*p)[curr];
}

ConstStrBlobPtr &ConstStrBlobPtr::incr()
{
    check(curr, "Increment out of bound");
    ++curr;
    return *this;
}
